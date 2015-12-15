#include "morsetree.h"
#include "Binary_Tree.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

morsetree::morsetree()
{
	ifstream fin; 
	fin.open("morse.txt");

	if (fin.bad())
		error("File Not Found");

	string line = "";
	char letter = '\0'; 
	BTNode <char> root(letter); 
	BTNode <char> *iter; 

	while (fin >> line)
	{
		if (line == "")
			error("Blank line in morse.txt");

		letter = line[0];
		line = line.substr(1);
		iter = &root; 
		//for (int i = 0; i < line.length(); i++)
		while (line != "")
		{
			//cout << "i: " << i << "\tline.length(): " << line.length() << endl; 
			if (line[0] == '.')
			{
				if (iter->left != NULL)
				{
					iter = iter->left;
					line = line.substr(1);
					cout << "Went Left, ";
				}
				else
				{
					BTNode<char> current(letter);
					iter->left = &current;
					cout << "added letter: " << letter << ','; 
					//line = line.substr(1);
					line = "";
				}
			}

			else if (line[0] == '_')
			{
				if (iter->right != NULL)
				{
					iter = iter->right;
					line = line.substr(1);
					cout << "Went Right, ";
				}

				else
				{
					BTNode<char> current(letter);
					iter->right = &current;
					cout << "added letter: " << letter << ',';
					//line = line.substr(1);
					line = ""; 
				}
			}

			else
				error("Invalid symbol - must be '.' or '_' ");

			cout << endl; 
		}
	}
}

void morsetree::error(string s)
{
	// Accept a string that describes the error, shows it on the console and halts further execution
	cerr << "ERROR: " << s << endl;
	system("PAUSE");
	exit(0);
}

morsetree::~morsetree()
{
}
