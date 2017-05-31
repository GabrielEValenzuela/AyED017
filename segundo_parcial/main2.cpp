#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

#include "structures.h"

// Prototypes
char main_menu(char&);
char structure_menu(char&);
char sorting_menu(char&);
char method_menu(char&);
fstream _open_file(string);
void _write_file(string, string);

int main() {
	string file_name;
	ifstream ifile;
	char opt;

	main_menu(opt);

	switch (opt) {
		case 'o':
			cout << "Ingrese el nombre del archivo: "
			cin >> file_name;
			try {
				f = _open_file(file_name);
			} catch (std::exception &ex) {
				cout << ex.what();
			}
			break;
		case 'x':
			return 0;
	}

	structure_menu(opt);
	switch (opt) {
		case 'a':
			structures::TreeAVL tree;
			break;
		case 'b':
			structures::BinaryTree tree;
			break;
		case 'x':
			return 0;
	}

	method_menu(opt);
	switch (opt) {
		case 'i':
			metodo_iterativo(file, tree);
			break;
		case 'r':
			metodo_recursivo(file, tree);
			break;
		case 'x':
			return 0;
	}

	cout << "Árbol: " << endl;
	tree.print();

	structures::List lista;
	lista.from_tree(tree.get_root());

	sorting_menu(opt);
	switch (opt) {
		case 'i':
			cout << "Ordenando utilizando método de insercion." << endl;
			lista.sort_insertion();
		case 'h':
			cout << "Ordenando utilizando método heap." << endl;
			lista.sort_heap();
		case 'x':
			return 0;
	}

	string result = lista.to_string();

	end_menu(opt);
	switch (opt) {
		case 'b':
			cout << result << endl
				 << "Imprimiendo a archivo. Ingrese el nombre: ";
			string out_file;
			cin >> out_file;
			_write_file(out_file, result);
		case 'p':
			cout << "Imprimiendo a archivo. Ingrese el nombre: ";
			string out_file;
			cin >> out_file;
			_write_file(out_file, result);
		case 's':
			cout << result << endl;
			break;
		case 'x':
			return 0;
	}

	return 0;
}

void main_menu(char& opt) {
	cout << " ----- Menu Principal -----"
		 << "Elija una opcion: " << endl
		 << "'o' -- Abrir archivo" << endl
		 << "'x' -- Salir" << endl
		 << ">> ";

	cin >> opt;
}

void structure_menu(char& opt) {
	cout << " ----- Menu Estructura -----"
		 << "Elija una estructura: " << endl
		 << "'a' -- AVL" << endl
		 << "'b' -- BTS" << endl
		 << "'x' -- Salir" << endl
		 << ">> ";

	cin >> opt;
}

void sorting_menu(char& opt) {
	cout << " ----- Menu Ordenamiento -----"
		 << "Elija un metodo de ordenamiento: " << endl
		 << "'h' -- Heap" << endl
		 << "'i' -- Insertion" << endl
		 << "'x' -- Salir" << endl
		 << ">> ";

	cin >> opt;
}

void method_menu(char& opt) {
	cout << " ----- Menu Metodo Llenado -----"
		 << "Elija un metodo llenado: " << endl
		 << "'i' -- Iterativo" << endl
		 << "'r' -- Recursivo" << endl
		 << "'x' -- Salir" << endl
		 << ">> ";

	cin >> opt;
}

fstream _open_file(string filename) {
	fstream file;
	file.exceptions(fstream::failbit | fstream::badbit);

	try {
		file.open(filename, ios::in);
		return file;
	}
	catch (...) {
		throw invalid_argument("Invalid file name");
	}
}

void _write_file(string filename, string content) {
	ofstream f = _open_file(filename);

	f << content;

	f.close();
}