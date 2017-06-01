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
		if (node == NULL) return 0;
		else return node->height;
	}

	int BinaryTree::get_height() {
		return _get_height(root);
	}

	Node BinaryTree::_insert(Node& node, string word) {
		if (node == NULL) {
			Node tmp = new sNode;
			tmp->word = word;
			tmp->repetitions = 1;
			tmp->height = 1;
			tmp->left = tmp->right = NULL;

			return tmp;
		}

		if (word < node->word) node->left = _insert(node->left, word);
		if (word > node->word) node->right = _insert(node->right, word);
		if (word == node->word) { 
			node->repetitions++;
			return node;
		}
	}

	void BinaryTree::insert(string word) {
		root = _insert(root, word);
	}

	void BinaryTree::_show(Node& node, int n) {
		int i;
	   	if(node!=NULL){
			_show(node->right, n+1);
			for(i=1; i<=n; i++) std::cout<<"     ";
			std::cout << node->word << "(" << node->height << ")" << endl;
			_show(node->left, n+1);
	   	}
	}

	int TreeAVL::_get_balance(Node& node) {
    	if (node == NULL) return 0;
    	return _get_height(node->left) - _get_height(node->right);
	}

	Node TreeAVL::_R_rotation(Node& y) {
	    Node x = y->left;
	    Node T2 = x->right;
	 
	    // Perform rotation
	    x->right = y;
	    y->left = T2;
	 
	    // Update heights
	    y->height = max(_get_height(y->left), _get_height(y->right))+1;
	    x->height = max(_get_height(x->left), _get_height(x->right))+1;
	 
	    // Return new root
	    return x;
	}

	Node TreeAVL::_L_rotation(Node& x) {
	    Node y = x->right;
	    Node T2 = y->left;
	 
	    // Perform rotation
	    y->left = x;
	    x->right = T2;
	 
	    //  Update heights
	    x->height = max(_get_height(x->left), _get_height(x->right))+1;
	    y->height = max(_get_height(y->left), _get_height(y->right))+1;
	 
	    // Return new root
	    return y;
	}

	Node TreeAVL::_insert(Node& node, string word) {
		if (node == NULL) {
			Node tmp = new sNode;
			tmp->word = word;
			tmp->repetitions = 1;
			tmp->height = 1;
			tmp->left = tmp->right = NULL;

			return tmp;
		}

		if (word < node->word) node->left = _insert(node->left, word);
		if (word > node->word) node->right = _insert(node->right, word);
		if (word == node->word) { 
			node->repetitions++;
			return node;
		}

		node->height = 1 + max(_get_height(node->left), _get_height(node->right));
		int balance = _get_balance(node);

		if (balance > 1 && word < node->left->word)
        return _R_rotation(node);
 
	    // Right Right Case
	    if (balance < -1 && word > node->right->word)
	        return _L_rotation(node);
	 
	    // Left Right Case
	    if (balance > 1 && word > node->left->word)
	    {
	        node->left =  _L_rotation(node->left);
	        return _R_rotation(node);
	    }
	 
	    // Right Left Case
	    if (balance < -1 && word < node->right->word)
	    {
	        node->right = _R_rotation(node->right);
	        return _L_rotation(node);
	    }
	 
	    /* return the (unchanged) node pointer */
	    return node;
	}

	void TreeAVL::insert(string word) {
		root = _insert(root, word);
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
		unsigned int heap_size = lista.size() / 2;
		int size = lista.size();
		Node temp;

		while (true) {

			if (heap_size > 0) {
				temp = lista[--heap_size];
				comp++;
			}
			else {
				size--;
				if (size == 0) {
					std::cout << "Cantidad de comparaciones (heap sort): " << comp << endl;
					return;
				}
				temp = lista[size];
				lista[size] = lista[0];
			}

			index = heap_size;
			child = index * 2 + 1;

			while (child < size) {
				comp++;
				if (child + 1 < size && lista[child + 1]->repetitions <= lista[child]->repetitions) {
					child++;
				}
				comp++;
				if (lista[child]->repetitions < temp->repetitions) {
					lista[index] = lista[child];
					index = child;
					child = index * 2 + 1;
				}
				else break;
			}

			lista[index] = temp;
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
