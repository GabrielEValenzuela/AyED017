//#include "stdafx.h"
#include <sstream>
#include <string>
#include <vector>


namespace structures {
	struct sNode {
		std::string word;
		int repetitions;
		sNode* left;
		sNode* right;
		void set_right(sNode* new_node) { right = new_node; };
		void set_left(sNode* new_node) { right = new_node; };
	};
	typedef sNode* Node;

	class BinaryTree {
	protected:
		Node root;
		Node _find(Node& node, std::string word);
		int _get_height(Node& node);
		void _node_add(Node& node, std::string word);
		int count(Node& node);

	public:
		BinaryTree() { root = NULL; };
		// ~Tree();
		void node_add(std::string word);
		void increment_reps(std::string word);
		int get_height();
		Node& get_root() { return root; }
		bool has(std::string word);
		Node find(std::string word);
		int get_amount_of_nodes();
	};


class TreeAVL : public BinaryTree {
	private:
		void _check_balance(Node& root);
		void _balance(Node& root);
		void _single_left_rotation(Node& root);
		void _single_right_rotation(Node& root);
		void _double_left_rotation(Node& root);
		void _double_right_rotation(Node& root);
	public:
		void node_add(std::string word);
};

	class List {
	private:
		std::vector<Node> lista;
		void _ird(Node& node);

	public:
		List() {};
		void add(Node& node);
		void from_tree(Node& node) { _ird(node); };
		void sort_insertion();
		void sort_heap();
		std::string to_string();
	};
}
