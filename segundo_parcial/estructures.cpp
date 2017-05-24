#include <sstream>
#include <string>

#include "estructures.h"

using std::string;
using std::max;

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

    Node* BinaryTree::_find(Node& node, string word) {
    	if (node == NULL) return NULL;
    	if (node->word == word) return node;
    	if (word < node->word) return _find(node->left, word);
    	if (word > node->word) return _find(node->right, word);
    }

    Node* BinaryTree::find(string word) {
    	return _find(root, word);
    }

    int BinaryTree::has(string word) {
    	if (find(word) != NULL) return true;
    	return false;
    }

    void BinaryTree::increment_reps(string word) {
    	find(word).repetitions++;
    }

    void BinaryTree::_node_add(Node& node, string word) {
    	if (node == NULL) {
    		node = new Node;
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

    void BinaryTree::node_delete(string word) {
    	// TODO: implement
    }

    void TreeAVL::node_add(string word) {
    	// TODO: implement
    }

    void TreeAVL::node_delete(string word) {
    	// TODO: implement
    }

    void List::sort_insertion() {
    	// TODO: implement
    }

    void List::sort_heap() {
    	// TODO: implement
    }

    string List::_to_string(Node& node, ostringstream& stm) {
    	if (node == NULL) return stm.str();
    	stm << node->word << endl;
    	return to_string(node->next, stm);
    }

    string List::to_string() {
    	ostringstream stm;
    	return _to_string(start, stm);
    }
}
