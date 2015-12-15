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
	BTNode < char > root(letter); 
	BTNode <char> iter(letter); 

	while (fin >> line)
	{
		if (line == "")
			error("Blank line in morse.txt");

		letter = line[0];
		
		for (int i = 1; i < line.length(); i++)
		{
			if (line[i] == '.')
			{
				if (iter.left == NULL && i == 1 - line.length())
				{
					BTNode<char> current(letter);
					iter.left = &current; 
				}	
				else if (iter.left != NULL)
					iter = *iter.left;
				else
					error("Predecessor node not available");
			}

			else if (line[i] == '_')
			{
				if (iter.right == NULL && i == 1 - line.length())
				{
					BTNode<char> current(letter);
					iter.right = &current;
				}
				else if (iter.right != NULL)
					iter = *iter.right;
				else
					error("Predecessor node not available");
			}

			else
				error("Invalid symbol - must be '.' or '_' ");
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
