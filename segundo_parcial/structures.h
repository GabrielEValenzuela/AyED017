#include <sstream>
#include <string>
#include <vector>


namespace structures {
	struct sNode {
		std::string word;
		int repetitions;
		int balance_factor;
		sNode* left;
		sNode* right;
		void set_right(sNode* node) {
			right = node;
			balance_factor--;
		}
		void set_left(sNode* node) {
			left = node;
			balance_factor++;
		}
	};
	typedef sNode* Node;

	class BinaryTree {
	protected:
		Node root;
		Node _find(Node& node, std::string word);
		int _get_height(Node& node);
		void _node_add(Node& node, std::string word);
		int count(Node& node);
		void _show(Node& node, int n);

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
		void print() { _show(root, 0); };
	};


	class TreeAVL : public BinaryTree {
	private:
		void _L_rotation(Node& root);
		void _R_rotation(Node& root);
		void _RL_rotation(Node& root);
		void _LR_rotation(Node& root);
		void _node_add(Node& node, std::string word);
		static int _get_balance(Node& node);
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
		void new_sort_heap();
		int leftChild(int i);
		void percDown();
		std::string to_string();
	};
}
