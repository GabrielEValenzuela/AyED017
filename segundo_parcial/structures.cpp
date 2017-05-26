#include <sstream>
#include <string>

#include "structures.h"

using std::string;	using std::ostringstream;
using std::max;		using std::endl;

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

    void BinaryTree::_del(Node& root) {
    	if (root->right != NULL) _del(root->right);
    	else {
    		Node tmp = root;
    		root = root->left;
    	}
    }

    void BinaryTree::_delete(Node& root, string word) {
    	if (word < root->word) _delete(root->left, word);
    	else if (word > root->word) _delete(root->right, word);
    	else {
    		Node tmp = root;
    		if (tmp->right == NULL) root = tmp->left;
    		else if (tmp->left == NULL) root = tmp->right;
    		else _del(tmp->left);
    		delete tmp;
    	}
    }

    void BinaryTree::node_delete(string word) {
    	if (!has(word)) return;

    	_delete(root, word);
    }

    void TreeAVL::node_add(string word) {
    	return;
    }

    void TreeAVL::node_delete(string word) {
    	return;
    }

    Node* List::_list_from_tree(Node* root) {
        if (root == NULL) return root;

        if (root->left != NULL) {
            Node* left = _list_from_tree(start, root->left);
            
            while (left->right != NULL) left = left->right;
            left->right = root;
            root->left = left;
        }

        if (root->right != NULL) {
            Node* right = _list_from_tree(start, root->right);
            
            while (right->left != NULL) right = right->left;
            right->left = root;
            root->right = right;
        }

        return root;
    }

    void List::_sort_insertion(Node& sorted, Node& to_sort) {
    	if (to_sort == NULL) return;

    	// guardo una referencia al proximo a ordenar
    	Node& next_to_sort = to_sort->right;

    	// saco a to_sort de la lista
    	sorted->right = to_sort->right;
    	to_sort->right->left = sorted;

    	//inserto a to_sort donde corresponda
    	while (true) {
    		// inserto to_sort después del primero mayor o igual que encuentre
    		if (sorted->repetitions >= to_sort->repetitions) {
    			sorted->right->left = to_sort;
    			to_sort->right = sorted->right->left;
    			sorted->right = to_sort;
    			to_sort->left = sorted;
    			// salgo del loop
    			break;
    		} else {
    			// si llegue al principio de la lista
    			if (sorted->left == NULL) {
    				sorted->left = to_sort;
    				to_sort->left = NULL;
    				to_sort->right = sorted;
    				start = to_sort;
                    // salgo del loop
    				break;
    			} else {
    				sorted = sorted->left;
    			}
    		}
    	}

    	// llamo recursivamente sobre el resto de la lista
    	_sort_insertion(next_to_sort->left, next_to_sort);
    }

    void List::sort_insertion() {
    	_sort_insertion(start, start->right);
    }

    void List::sort_heap() {
    	return;
    }

    string List::_to_string(Node& node, ostringstream& stm) {
    	if (node == NULL) return stm.str();
    	stm << node->word << endl;
    	return _to_string(node->right, stm);
    }

    string List::to_string() {
    	ostringstream stm;
    	return _to_string(start, stm);
    }
}