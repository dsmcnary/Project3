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
 
	BTNode<char> root('\0', NULL, NULL);
	BTNode<char>* rootPtr = &root;
	// Read in one line at a time
	while (fin >> line)
	{
		// First char of each line is the alphabetic letter
		letter = line[0];
		cout << letter << endl; 
		line = line.substr(1);							// remove this letter from rest of line (code)
		addNode(line, rootPtr, letter);
	}
}

string morsetree::decode(string s)
{
	BTNode <char> *iter;
	string message = ""; 

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

void morsetree::addNode(string s, BTNode<char>* localRoot, char c)
{ 
	//cout << "Working on: " << c << endl; 
	if (s.length() == 1)
	{
		//cout << "1 character in string" << endl; 
		BTNode<char>* newNode = new BTNode<char>(c);	

		if (s[0] == '.')
		{
			localRoot->left = newNode;
			cout << "New Left Node created: " << localRoot->data << '\t' << localRoot->left->data << endl;
		}
		else if (s[0] == '_')
		{
			localRoot->right = newNode;
			cout << "New Right Node created: " << localRoot->data << '\t' << localRoot->right->data << endl;
		}
		return; 
	}

	else
	{
		//cout << "Going left/right" << endl; 
		if (s[0] == '.')
			return addNode(s.substr(1), localRoot->left, c);
		else if (s[0] == '_')
			return addNode(s.substr(1), localRoot->right, c);
	}

	return;
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