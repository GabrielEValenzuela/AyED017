#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "structures.h"

using namespace std;

int main() {
	string buffer[] = {"hola", "hola", "test", "hola", "test", "prueba", "ccc", "aaa"};
	vector<string> list_of_words(buffer, buffer+8);
	cout << "Lista de palabras creada" << endl;

	cout << "Creando arbol" << endl;
	structures::BinaryTree arbol;

	vector<string>::iterator it;
	for (it = list_of_words.begin(); it != list_of_words.end(); it++) {
		cout << "Agregando: " << *it << endl;
		if (arbol.has(*it)) arbol.increment_reps(*it);
		else arbol.node_add(*it);
		cout << *it << " agregado." << "Repeticiones: " 
		     << arbol.find(*it)->repetitions << endl;
	}

	cout << "Creando lista" << endl;
	structures::List lista;
	lista.from_tree(arbol.get_root());
	cout << lista.to_string();

	cout << "Ordenando lista (heap)" << endl << endl;
	lista.sort_heap();
	cout << lista.to_string();

	cout << "---------------------------------------------" << endl;
	cout << "Creando arbol AVL" << endl;
	structures::TreeAVL avl;

	for (it = list_of_words.begin(); it != list_of_words.end(); it++) {
		cout << "Agregando: " << *it << endl;
		if (avl.has(*it)) avl.increment_reps(*it);
		else avl.node_add(*it);
		cout << *it << " agregado." << "Repeticiones: " 
		     << avl.find(*it)->repetitions << endl;

		cout << endl;
		avl.print();
	}

	cout << "Creando lista" << endl;
	structures::List lista2;
	lista2.from_tree(avl.get_root());
	cout << lista2.to_string();

	cout << "Ordenando lista" << endl << endl;
	lista2.sort_insertion();
	cout << lista2.to_string();	

	cout << "---------------------------------------------" << endl;
	cout << "Probando creacion de arbol desde archivo" << endl;
	structures::TreeAVL tree;
	ifstream f;
	string buffer2;

	f.open("test.txt");

	while (f >> buffer2) {
		std::transform(buffer2.begin(), buffer2.end(), buffer2.begin(), ::tolower);
		if (tree.has(buffer2)) {
			tree.increment_reps(buffer2);
			cout << "Aumentando: " << buffer2 << endl;
		}
		else {
			tree.node_add(buffer2);
			cout << "Agregando: " << buffer2 << endl;
		}
	}

	avl.print();

	return 0;
}