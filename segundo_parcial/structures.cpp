//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "structures.h"

using std::string;	using std::ostringstream;
using std::max;		using std::min;
using std::vector;	using std::endl;

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
			// balance_factor = 0;
			node->left = node->right = NULL;
		}

		if (word < node->word) _node_add(node->left, word);
		if (word > node->word) _node_add(node->right, word);
	}

	void BinaryTree::node_add(string word) {
		_node_add(root, word);
	}

	void BinaryTree::_show(Node& node, int n) {
		int i;
	   	if(node!=NULL){
			_show(node->right, n+1);
			for(i=1; i<=n; i++) std::cout<<"     ";
			std::cout << node->word << "(" << node->balance_factor << ")" << endl;
			_show(node->left, n+1);
	   		}
	}

	int TreeAVL::_get_balance(Node& node) {
		if (node == NULL) return 0;
		else return node->balance_factor;
	}

	void TreeAVL::_L_rotation(Node& root) {
		Node oldroot = root;
		root = root->right;
		oldroot->right = root->left;
		int oldfactor = _get_balance(root->left);
		root->left = oldroot;

		oldroot->balance_factor = _get_balance(oldroot->left) - oldfactor;
		root->balance_factor = _get_balance(root->left) - _get_balance(root->right);
	}

	void TreeAVL::_RL_rotation(Node& root) {
		_R_rotation(root->right);
		_L_rotation(root);
	}

	void TreeAVL::_R_rotation(Node& root) {
		Node oldroot = root;
		root = root->left;
		oldroot->left = root->right;
		int oldfactor = _get_balance(root->right);
		root->right = oldroot;

		oldroot->balance_factor = oldfactor - _get_balance(oldroot->right);
		root->balance_factor = _get_balance(root->left) - _get_balance(root->right);
	}

	void TreeAVL::_LR_rotation(Node& root) {
		_L_rotation(root->left);
		_R_rotation(root);
	}

	void TreeAVL::_node_add(Node& node, string word) {
		if (node == NULL) {
			node = new sNode;
			node->word = word;
			node->repetitions = 1;
			node->balance_factor = 0;
			node->left = node->right = NULL;
		}

		if (word < node->word) {
			node->balance_factor++;
			_node_add(node->left, word);
			if (node->balance_factor == 2) {
				if (node->left->balance_factor > 0) {
					_R_rotation(node);
				} else {
					_LR_rotation(node);
				}
			}
		}
		if (word > node->word) {
			node->balance_factor--;
			_node_add(node->right, word);
			if (node->balance_factor == -2) {
				if (node->right->balance_factor < 0) {
					_L_rotation(node);
				} else {
					_RL_rotation(node);
				}
			}
		}
	}

	void TreeAVL::node_add(string word) {
		_node_add(root, word);
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

		std::cout << "Cantidad de comparaciones (insertion sort): " << comp << endl;
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
				if (size == 0) { 
					std::cout << "Cantidad de comparaciones (heap sort): " << comp << endl; 
					return;
				}
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
