#include <iostream>
#include <vector>
#include <string>

#include "structures.h"

using namespace std;

int main() {
	string buffer[] = {"hola", "hola", "hola", "test", "hola", "test", "prueba", ""};
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

	cout << "Creando arbol AVL" << endl;
	structures::TreeAVL avl;

	for (it = list_of_words.begin(); it != list_of_words.end(); it++) {
		cout << "Agregando: " << *it << endl;
		if (avl.has(*it)) avl.increment_reps(*it);
		else avl.node_add(*it);
		cout << *it << " agregado." << "Repeticiones: " 
		     << avl.find(*it)->repetitions << endl;
	}

	cout << "Creando lista" << endl;
	structures::List lista2;
	lista2.from_tree(avl.get_root());
	cout << lista2.to_string();

	cout << "Ordenando lista" << endl << endl;
	lista2.sort_insertion();
	cout << lista2.to_string();	

	return 0;
}