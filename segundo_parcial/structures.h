#include <sstream>
#include <string>
#include <vector>


namespace structures {
	struct sNode {
		std::string word;
		int repetitions;
		int height;
		sNode* left;
		sNode* right;
	};
	typedef sNode* Node;

	class BinaryTree {
	protected:
		Node root;
		Node _find(Node& node, std::string word);
		static int _get_height(Node& node);
		Node _insert(Node& node, std::string word);
		void _show(Node& node, int n);

	public:
		BinaryTree() { root = NULL; };
		// ~Tree();
		void insert(std::string word);
		int get_height();
		Node& get_root() { return root; }
		void print() { _show(root, 0); };
	};


class TreeAVL : public BinaryTree {
	private:
		Node _L_rotation(Node& root);
		Node _R_rotation(Node& root);
		Node _insert(Node& node, std::string word);
		static int _get_balance(Node& node);
	public:
		void insert(std::string word);
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

