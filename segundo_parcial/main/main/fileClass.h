#ifndef FILECLASS_H
#define FILECLASS_H
#include <string>

using namespace std;

class fileClass
{
public:
	/*
		Constructor de la clase file
		@param: Vac�o
	*/
	fileClass();


	/*
		openFile: Abre un archivo de acuerdo al nombre y extensi�n especificada
		@param: Nombre del archivo dot extensi�n
	*/
	string openFile(string filename);


	/*
		Crea un archivo biario con el nombre especificado
		@param: Nombre del archivo
	*/
	void createBinaryFile(string filename);


	/*
	Crea un archivo biario con el nombre especificado
	@param: Nombre del archivo
	*/


	void createTextFile(string filename);


	/*
		Destructor
		@Param: Vac�o
	*/
	~fileClass();
};

#endif