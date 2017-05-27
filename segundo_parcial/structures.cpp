#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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

    void TreeAVL::node_add(string word) {
    	return;
    }

    int List::_ird(Node& node) {
        if (node!=NULL) {
            _ird(node->left);
            lista.push_back(node);
            _ird(node->right);
        }
    }

    void List::sort_insertion() {
        int i,j, comp;
        Node di;
        for (int i = 1; i < lista.size(); i++){
            j = i-1; 
            di = lista[i]; 
            comp++;
            while(di->repetitions < lista[j]->repetitions && j >= 0){
                lista[j+1] = lista[j];
                comp++;
                j--;
            }
            lista[j+1] = di;
        }
    }

    void List::sort_heap() {
    	return;
    }

    string List::to_string() {
    	vector<Node>::reverse_iterator iter;
        ostringstream stm;
        
        for (iter = lista.rbegin(); iter != lista.rend(); iter++) {
            stm << (*iter)->word << " " << (*iter)->repetitions << endl;    
        }

        return stm.str();
    }
}