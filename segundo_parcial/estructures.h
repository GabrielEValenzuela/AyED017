#include <string>

namespace estructures {
    class Node {
        std::string word;
        int repetitions;
        Node* left;
        Node* right;
    };

    class Tree {
        private:
            Node* root;

        public:
            Tree() { root = NULL; };
            // ~Tree();
            void node_add(std::string word) = 0;
            void node_delete(std::string word) = 0;
            int get_height();
            void increment_reps(std::string word);
    };
    
    class TreeBinary: public Tree {
        private:
        public:
            void node_add(std::string word);
            void node_delete(std::string word);
    };
    
    class TreeAVL: public Tree {
        private:
        public:
            void node_add(std::string word);
            void node_delete(std::string word);
    };
    
    class List {
        private:
            Node* start;

        public:
            List() { start = NULL };
            List(Node& node) { start = node; };
            void sort_insertion();
            void sort_heap();
            std::string to_string();
    };
}
