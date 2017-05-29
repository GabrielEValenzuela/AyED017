//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "structures.h"

using std::string;	using std::ostringstream;
using std::max;		using std::endl;
using std::vector;

namespace structures {
	int BinaryTree::_get_height(Node& node) {
		if (node == NULL) return -1;
		int left = _get_height(node->left);
		int right = _get_height(node->right);

		return 1 + max(left, right);
	}

	int BinaryTree::get_height() {
		return _get_height(root);
	}

	Node BinaryTree::_find(Node& node, string word) {
		if (node == NULL) return NULL;
		if (node->word == word) return node;
		if (word < node->word) return _find(node->left, word);
		if (word > node->word) return _find(node->right, word);
	}

	Node BinaryTree::find(string word) {
		return _find(root, word);
	}

	bool BinaryTree::has(string word) {
		if (find(word) != NULL) return true;
		return false;
	}

	void BinaryTree::increment_reps(string word) {
		find(word)->repetitions++;
	}

	void BinaryTree::_node_add(Node& node, string word) {
		if (node == NULL) {
			node = new sNode;
			node->word = word;
			node->repetitions = 1;
			node->left = node->right = NULL;
		}

		if (word < node->word) _node_add(node->left, word);
		if (word > node->word) _node_add(node->right, word);
	}

	void BinaryTree::node_add(string word) {
		_node_add(root, word);
	}

	void TreeAVL::_single_left_rotation(Node& root) {
		Node tmp = root;
		root = root->left;
		root->right = tmp;
	}

	void TreeAVL::_double_left_rotation(Node& root) {
		Node tmp = root->left;
		root->left = root->left->right;
		root->left->left = tmp;
		_single_left_rotation(root);
	}

	void TreeAVL::_single_right_rotation(Node& root) {
		Node tmp = root;
		root = root->right;
		root->left = tmp;
	}
	void TreeAVL::_double_right_rotation(Node& root) {
		Node tmp = root->right;
		root->right = root->right->left;
		root->right->right = tmp;
	}

	void TreeAVL::_balance(Node& root) {
		int balance = BinaryTree::_get_height(root->left) - BinaryTree::_get_height(root->right);

		if (balance == 2) {
			 if (BinaryTree::_get_height(root->left) != 0) _single_right_rotation(root);
			 else _double_right_rotation(root);
		} else if (balance == -2) {
			if (BinaryTree::_get_height(root->right) != 0) _single_left_rotation(root);
			 else _double_left_rotation(root);
		}

		if (balance > 2)
			_balance(root->left);
		else if (balance < -2) 
			_balance(root->right);
	}

	void TreeAVL::_check_balance(Node& root) {
		int balance = BinaryTree::_get_height(root->left) - BinaryTree::_get_height(root->right);
		bool is_balanced = abs(balance) > 1;

		if (!is_balanced) {
			_balance(root);
		}

	}

	void TreeAVL::node_add(string word) {
		BinaryTree::node_add(word);

		_check_balance(root);
	}

	void List::_ird(Node& node) {
		if (node != NULL) {
			_ird(node->left);
			lista.push_back(node);
			_ird(node->right);
		}
	}

	void List::sort_insertion() {
		// if (lista.size() == 0) return;
		int comp = 0;
		for (int i = 1; i < lista.size(); i++) {
			for (int j = i; j > 0; j--) {
				if (lista[j]->repetitions > lista[j-1]->repetitions) {
					comp++;
					Node tmp = lista[j];
					lista[j] = lista[j-1];
					lista[j-1] = tmp;
				} else break;
			}
		}
	}

	void List::sort_heap() {
		if (lista.size() == 0) { return; }
		int comp = 0;
		int index, child;
		int heap_size = lista.size() / 2, size = lista.size();
		Node di;

		while (true) {

			if (heap_size > 0) {
				di = lista[--heap_size];
				comp++;
			}
			else {
				size--;
				if (size == 0) { return; }
				di = lista[size];
				lista[size] = lista[0];
			}

			index = heap_size;
			child = index * 2 + 1;

			while (child < size) {
				comp++;
				if (child + 1 < size && lista[child + 1] > lista[child]) {
					child++;
				}
				comp++;
				if (lista[child] > di) {
					lista[index] = lista[child];
					index = child;
					child = index * 2 + 1;
				}
				else break;
			}

			lista[index] = di;
		}
		return;
	}

	string List::to_string() {
		vector<Node>::iterator iter;
		ostringstream stm;

		for (iter = lista.begin(); iter != lista.end(); iter++) {
			stm << (*iter)->word << " " << (*iter)->repetitions << endl;
		}

		return stm.str();
	}
}
