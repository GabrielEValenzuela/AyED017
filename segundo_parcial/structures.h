#include <sstream>
#include <string>

namespace structures {
    struct sNode {
        std::string word;
        int repetitions;
        sNode* left;
        sNode* right;
    };
    typedef sNode* Node;

    class BinaryTree {
        private:
            Node root;
            Node _find(Node& node, std::string word);
            int _get_height(Node& node);
            void _node_add(Node& node, std::string word);
            void _delete(Node& node, std::string word);
            void _del(Node& node);

        public:
            BinaryTree() { root = NULL; };
            // ~Tree();
            void node_delete(std::string word);
            void node_add(std::string word);
            void increment_reps(std::string word);
            int get_height();
            bool has(std::string word);
            Node find(std::string word);
    };
    
    class TreeAVL: public BinaryTree {
        private:
        public:
            void node_add(std::string word);
            void node_delete(std::string word);
    };
    
    class List {
        private:
            Node start;
            std::string _to_string(Node& node, std::ostringstream& stm);
            void _sort_insertion(Node& sorted, Node& to_sort);

        public:
            List() { start = NULL; };
            List(Node& node) { start = node; };
            void sort_insertion();
            void sort_heap();
            std::string to_string();
    };
}
