// Daniel McNary
// Professor Kuhail
// CS 303
// 12/16/2015

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
 
	BTNode<char>* rootPtr = new BTNode<char>('\0'); 
	masterRoot = rootPtr; 

	// Read in one line at a time
	while (fin >> line)
	{
		// First char of each line is the alphabetic letter
		letter = line[0];
		cout << letter << endl; 
		line = line.substr(1);							// remove this letter from rest of line (code)
		encodeMap.insert(pair<char, string>(letter, line));
		addNode(line, rootPtr, letter);
	}
	cout << pre_order(rootPtr) << endl;
}

string morsetree::decode(string s)
{
	string token = "";
	string message = "";
	while (s.length() != 0)
	{
		if (s.find(" ") == string::npos)
		{
			token = s;
			s = "";
		}

		else if (s.find(" ") > 0)
		{
			token = s.substr(0, s.find(" "));
			s = s.substr(s.find(" ") + 1);
		}

		message += decodeToken(masterRoot, token);
	}

	return message; 
}

char morsetree::decodeToken(BTNode<char>* localRoot, string s)
{
	if (s == "")
	{
		return localRoot->data; 
	}

	if (s[0] == '.')
		return decodeToken(localRoot->left, s.substr(1));
	else
		return decodeToken(localRoot->right, s.substr(1));
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

string morsetree::pre_order(const BTNode<char>* local_root) const 
{
	string result;

	if (local_root != NULL) {
		result += local_root->to_string();

		if (local_root->left != NULL) {
			result += " ";
			result += pre_order(local_root->left);
		}

		if (local_root->right != NULL) {
			result += " ";
			result += pre_order(local_root->right);
		}
	}
	return result;
}

void morsetree::printMap()
{
	map<char, string>::iterator itr;

	for (itr = encodeMap.begin(); itr != encodeMap.end(); itr++)
		cout << itr->first << '\t' << itr->second << endl; 
}

string morsetree::encodeMessage(string s)
{
	string morse; 

	for (unsigned int i = 0; i < s.length(); i++)
	{
		morse += encodeMap.find(s[i])->second;
		morse += " "; 
	}

	return morse; 
}