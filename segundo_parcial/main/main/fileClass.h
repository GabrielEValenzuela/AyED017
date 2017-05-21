#ifndef FILECLASS_H
#define FILECLASS_H
#include <string>

using std::fstream;		using std::string;

class fileClass {
	public:
		/* Constructor de la clase file	*/
		fileClass() {};
		// ~fileClass();

		/* openFile: Abre un archivo de acuerdo al nombre y extensión especificada
		   @param: Nombre del archivo dot extensión
		*/
		fstream& openFile(string filename);
};

#endif
