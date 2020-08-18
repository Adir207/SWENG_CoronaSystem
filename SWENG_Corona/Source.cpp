#include<iostream>
#include<fstream>
#include"Executer.h"
using namespace std;
int main()
{
	string filename;
	string extension = "";
	ifstream fin;
	do
	{
		cout << "Enter command file name(only .txt files): ";
		getline(cin, filename);
		extension = filename;
		size_t pos = 0;
		string delimiter = ".";
		string token;
		pos = extension.find(delimiter);
		extension.erase(0, pos + delimiter.length());
		fin.open(filename);
		if (fin.fail() || extension != "txt")
			cout << "FAILED: Wrong filename or extension\n";
	} while (extension != "txt" || fin.fail());
	fin.close();
	Executer* executer = Executer::getInstance();
	executer->parseInputFile(filename);
	system("pause");
	return 0;
}