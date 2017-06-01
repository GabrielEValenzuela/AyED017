#include "stdafx.h" //NO BORRAR
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "structures.h"

using namespace std;

// Prototypes
void main_menu(char&);
void structure_menu(char&);
void sorting_menu(char&);
void method_menu(char&);
void end_menu(char&);
void iterative_method(ifstream&, structures::TreeAVL& tree, string tree_type);
void recursive_method(ifstream&, structures::TreeAVL& tree, string tree_type);
fstream _open_file(string);
void _write_file(string, string);
void no_puntuations_marks(string &);
//
const string MARKS = ".;:;()[]{}<>";
//

int main() {
	string file_name, tree_type;
	ifstream f;
	structures::TreeAVL tree;
	char opt;

	string s1 = ".Prueba.";
	string s2 = "<>.Prueba;2.<>";

	cout << s1 << "  " << "  " << s2 << endl;
	cout << "Llamo a metodo no..." << endl;
	no_puntuations_marks(s1);
	no_puntuations_marks(s2);
	cout << s1 << "  " << "  " << s2 << endl;


	main_menu(opt);

	switch (opt) {
	case 'o':
		cout << "Ingrese el nombre del archivo: ";
		cin >> file_name;
		try {
			f.open(file_name.c_str());
		}
		catch (std::exception &ex) {
			cout << ex.what();
		}
		break;
	case 'x':
		return 0;
	}

	structure_menu(opt);
	switch (opt) {
	case 'a':
		tree_type = "AVL";
		break;
	case 'b':
		tree_type = "BTS";
		break;
	case 'x':
		return 0;
	}

	method_menu(opt);
	switch (opt) {
	case 'i':
		iterative_method(f, tree, tree_type);
		break;
	case 'r':
		recursive_method(f, tree, tree_type);
		break;
	case 'x':
		return 0;
	}

	structures::List lista;
	lista.from_tree(tree.get_root());

	sorting_menu(opt);
	switch (opt) {
	case 'i':
		cout << "Ordenando utilizando método de insercion." << endl;
		lista.sort_insertion();
		break;
	case 'h':
		cout << "Ordenando utilizando método heap." << endl;
		lista.sort_heap();
		break;
	case 'x':
		return 0;
	}

	string result = lista.to_string();
	string out_file;

	end_menu(opt);

	switch (opt) {
	case 'b':
		cout << result << endl;
	case 's':
		cout << "Imprimiendo a archivo. Ingrese el nombre: ";
		cin >> out_file;
		_write_file(out_file, result);
		break;
	case 'd':
		cout << result << endl;
		break;
	case 'x':
		return 0;
	}

	system("PAUSE");

	return 0;
}

void main_menu(char& opt) {
	cout << " ----- Menu Principal -----" << endl
		<< "Elija una opcion: " << endl
		<< "'o' -- Abrir archivo" << endl
		<< "'x' -- Salir" << endl
		<< ">> ";

	cin >> opt;
}

void structure_menu(char& opt) {
	cout << " ----- Menu Estructura -----" << endl
		<< "Elija una estructura: " << endl
		<< "'a' -- AVL" << endl
		<< "'b' -- BTS" << endl
		<< "'x' -- Salir" << endl
		<< ">> ";

	cin >> opt;
}

void sorting_menu(char& opt) {
	cout << " ----- Menu Ordenamiento -----" << endl
		<< "Elija un metodo de ordenamiento: " << endl
		<< "'h' -- Heap" << endl
		<< "'i' -- Insertion" << endl
		<< "'x' -- Salir" << endl
		<< ">> ";

	cin >> opt;
}

void method_menu(char& opt) {
	cout << " ----- Menu Metodo Llenado -----" << endl
		<< "Elija un metodo llenado: " << endl
		<< "'i' -- Iterativo" << endl
		<< "'r' -- Recursivo" << endl
		<< "'x' -- Salir" << endl
		<< ">> ";

	cin >> opt;
}

void end_menu(char& opt) {
	cout << " ----- Menu Finalizacion -----" << endl
		<< "Elija que hacer con el resultado: " << endl
		<< "'d' -- Mostrar" << endl
		<< "'s' -- Imprimir a archivo" << endl
		<< "'b' -- Ambas" << endl
		<< "'x' -- Salir" << endl
		<< ">> ";

	cin >> opt;
}

void _write_file(string filename, string content) {
	ofstream f;
	f.open(filename.c_str());

	f << content;

	f.close();
}

void iterative_method(ifstream& f, structures::TreeAVL& tree, string tree_type) {
	string buffer;
	while (f >> buffer) {
		std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
		if (tree.has(buffer)) tree.increment_reps(buffer);
		else {
			if (tree_type == "BTS") tree.structures::BinaryTree::node_add(buffer);
			else tree.node_add(buffer);
		}
	}
}

void recursive_method(ifstream& f, structures::TreeAVL& tree, string tree_type) {
	string buffer;
	if (f >> buffer) {
		std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
		if (tree.has(buffer)) tree.increment_reps(buffer);
		else {
			if (tree_type == "BTS") tree.structures::BinaryTree::node_add(buffer);
			else tree.node_add(buffer);
		}
		recursive_method(f, tree, tree_type);
	}
}

bool is_puntuations(char ch) {
	return MARKS.find(ch) != string::npos;
}

void no_puntuations_marks(string& str) {

	std::ostringstream buffer;

	string::const_iterator iter = str.begin();
	char next_ch = *iter;
		while (iter != str.end())
		{
			if (is_puntuations(next_ch)==false)
			{
				buffer.put(next_ch);
				iter++;
			}
		}

		str = buffer.str();
	}
