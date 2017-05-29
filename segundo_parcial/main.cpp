/*
Autor: Benitez, Jeremías
Autor: Valenzuela, Gabriel
Date: 06/01/17
*/

#include "stdafx.h"
#include "structures.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cctype>

//Using spaces
using std::cout;		using std::endl;
using std::fstream;		using std::string;
using std::exception;	using std::invalid_argument;
using std::ios;			using std::cin;
using std::setw;

//				***	Functions	***
/*
*	Abre el archivo
*	@param El nombre de archivo
*	@return El archivo si se abre exitosamente
*/
fstream _open_file(string filename);

/*
*	Lleva una cadena a minúscula
*	@param La cadena a trabajar
*/

void _to_lower_case(string& str);

/*
*	Escribe el archivo con las respuestas
*	@param Cadenas a escribir
*/

void _write_file(string content);

/*
*	Contenido del archivo
*	@param El archivo a leer
*/
void _show_file_content(fstream&);

/*
*	Metodo iterativo
*	@param Archivo de datos
*	@param El arbol binario
*/
void _iterative_method(fstream&,structures::BinaryTree&);

/*
*	Metodo iterativo
*	@param Archivo de datos
*	@param El arbol binario
*/
void _recursive_method(fstream&, structures::BinaryTree&);




int main()
{
	string fileName;	bool tryAgain = true;
	string buffer;		fstream file;
	char op;			structures::List _sorted_list;
	structures::BinaryTree _Btree;

_principal_menu:
	do {
		system("cls");
		cout << "Bienvenida, opcion: " << endl
			<< "\n 'o' -- Abrir archivo"
			<< "\n 'w' -- Escribir archivo"
			<< "\n 'x' -- Exit"
			<< "\n>> ";

		cin >> op;

		switch (op)
		{
		case 'o':
			cout << "Ingrese nombre de archivo: " << endl;
			cout << ">>";
			cin >> fileName;
			while (tryAgain) {
				try
				{
					file = _open_file(fileName);
					tryAgain = false;
					goto _file_menu;
				}
				catch (...)
				{
					cout << "Error, reintentar" << endl;
					cout << ">>";
					cin >> fileName;
				}
			}
			break;
		case 'w':
			_write_file("content");
			cout << "Archivo creado,salir ?" << endl;
			cout << ">> ";
			char rta;
			cin >> rta;
			if (rta == 'y' || rta == 'Y') {
				exit(0);
			}
			break;
		case'x':
			exit(0);
		default:
			cout << "?";
		}

	} while (true);

_file_menu:
	do {
		system("cls");
		cout << endl << "Mostrar contenido del archivo ?"
			<< "\n 'y' -- Si"
			<< "\n 'n' -- No"
			<< "\n 'r' -- Volver al menu principal"
			<< "\n>> ";
		cin >> op;

		switch (op) {
		case 'y':
			cout << endl << "Contenido del archivo original \n" << endl;
			cout << setw(35) << "---------------------------------- \n \n " << endl;
			_show_file_content(file);
			cout << endl << endl;
			goto _structure_options;
			break;
		case 'n':
			cout << "Omitiendo contenido...";
			goto _structure_options;
			break;
		case 'r':
			goto _principal_menu;
			break;
		default:
			cout << "?";
		}

	} while (true);
_structure_options:
	do {
		cout << endl << "Elegir metodo: "
			<< "\n 'i' -- Metodo iterativo"
			<< "\n 'r' -- Metodo recursivo"
			<< "\n 'a' -- Metodo AVL"
			<< "\n 'm' -- Regresar a menu principal"
			<< "\n>> ";
		cin >> op;

		switch (op) {
		case 'i':
			_iterative_method(file, _Btree);
			break;
		case 'r':
			_recursive_method(file,_Btree);
			break;
		case 'a':
			//avl_method();
			break;
		case 'm':
			goto _principal_menu;
		default:
			cout << endl << "?" << endl;
		}

	} while (true);

	getchar();
	getchar();
	system("PAUSE");
	return 0;
}

//					Function's code
//*********************************************************//
void _show_file_content(fstream& file)
{
	string buffer;

	try
	{
		while (file.good()) {
			getline(file, buffer);
			cout << setw(35) << buffer << endl;
			buffer.clear();
		}

	}
	catch (const std::exception&)
	{
		cout << "Error";
	}
}
//*********************************************************//
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
//*********************************************************//
void _to_lower_case(string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}
//*********************************************************//
void _write_file(string content)
{
	fstream file_solution;

	file_solution.open("Solution.txt", ios::out);
	file_solution.close();

	return;
}
//*********************************************************//
void _iterative_method(fstream& file, structures::BinaryTree& _Btree) {
	string buffer;
	while (file.good()) {
		file >> buffer;
		_to_lower_case(buffer);
		if (_Btree.has(buffer)) { _Btree.increment_reps(buffer); }
		_Btree.node_add(buffer);
		buffer.clear();
	}
}
//*********************************************************//
void _recursive_method(fstream& file, structures::BinaryTree& _Btree) {
	string str;
	if (cin >> str)
	{
		_to_lower_case(str);
		if (_Btree.has(str)) {
			_Btree.increment_reps(str);
		}
		_Btree.node_add(str);
		_recursive_method(file, _Btree);
	}
}
