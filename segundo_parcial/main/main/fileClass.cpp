#include "stdafx.h"
#include "fileClass.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

fileClass::fileClass()
{
}

string fileClass::openFile(string filename)
{
	{
		bool tryAgain = true;
		string str;
		string file_contents;

		fstream file;
		while (tryAgain) {
			try
			{
				file.open(filename, ios::in);

				if (file.fail())
				{
					throw - 1;
				}
				while (getline(file, str))
				{
					file_contents += str + '\n';
				}
				tryAgain = false;
				return file_contents;
				file.close();
			}
			catch (int e)
			{
				string again;
				cout << "Exception al abrir archivo para su lectur \n";
				cout << "Ingrese nombre correctamente >> ";
				
				cin>>again;
				

				return openFile(again);
			}
		}
	}

}




fileClass::~fileClass()
{
}
