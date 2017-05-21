#include <exception>
#include <iostream>
#include <fstream>
#include <string>

#include "stdafx.h"
#include "fileClass.h"

using std::fstream;		using std::string;
using std::exception;

fstream& fileClass::openFile(string filename) {
	fstream file;
	file.exceptions(fstream::failbit | fstream::badbit);

	try {
		file.open(filename);
		return file;
	} catch (const ifstream::failure& e) {
		throw invalid_argument("Invalid file name");
	}
}