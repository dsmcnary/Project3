#include "morsetree.h"
#include "Binary_Tree.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

morsetree::morsetree()
{
	// Open morse.txt to read in nodes
	ifstream fin; 
	fin.open("morse.txt");

	if (fin.bad())
		error("File Not Found");

	// Initialize variables
	string line = "";
	char letter = '\0';

	// Read in one line at a time
	while (fin >> line)
	{
		// First char of each line is the alphabetic letter
		letter = line[0];
		BTNode<char> newnode(letter, NULL, NULL);		// new node based on this letter
		line = line.substr(1);							// remove this letter from rest of line (code)

		while (line != "")								// Decode until no '.' or '_' remaining
		{ 
			if (line[0] == '.')							// Go left if dot
			{
				if (iter->left != NULL)
				{
					iter = iter->left;
					line = line.substr(1);
				}
				else
				{
					iter->left = &newnode;
					line = "";
				}
			}

			else if (line[0] == '_')					// Go right if dash
			{
				if (iter->right != NULL)
				{
					iter = iter->right;
					line = line.substr(1);
				}

				else
				{
					iter->right = &newnode;
					line = ""; 
				}
			}

			else
				error("Invalid symbol - must be '.' or '_' ");
		}
	}

	*masterRoot = root; 

	//cout << root.data << endl; 
	//cout << root.left->data << endl;
	//cout << root.right->data << endl; 
}

void morsetree::findNode(string s, Binary_Tree<char> tree, char c)
{
	if (s.length() == 1)
	{
		BTNode<char> newnode(c, NULL, NULL); 
		tree.get_left_subtree() = newnode; 
		return;
	}

	if (s[0] == '.')
		findNode(s.substr(1), tree.get_left_subtree(), c);
	else if (s[0] == '_')
		findNode(s.substr(1), tree.get_right_subtree(), c);
	else
		error("Unknown character in path");
}

void addNode(char c);

string morsetree::decode(string s)
{
	BTNode <char> *iter;
	string message = ""; 

//	cout << masterRoot->data << endl;
	//cout << masterRoot->left->data << endl;
	//cout << masterRoot->right->data << endl;

	while (s != "")
	{
		iter = masterRoot; 
		if (s[0] == '.')
		{
			//cout << "Going Left " << iter->data << endl;
			iter = iter->left;
			s = s.substr(1);
		}
		else if (s[0] == '_')
		{
			//cout << "Going Right" << iter->data << endl;
			iter = iter->right;
			s = s.substr(1);
		}
		else if (s[0] == ' ')
		{
			message += iter->data; 
			s = s.substr(1);
			//cout << "Data" << iter->data << endl;
			//cout << "Message: " << message << endl;
		}
		else
			error("Unknown character in decode string");
	}

	return message; 
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
