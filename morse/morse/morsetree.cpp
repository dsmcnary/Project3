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

// Default constructor
// Opens the morse.txt input file and stores appropriately in binary tree (decode) and a map (encode)
morsetree::morsetree()
{
	// Open morse.txt to read in nodes
	ifstream fin; 
	fin.open("morse.txt");

	// Check if file opened
	if (fin.bad())
		error("File Not Found");

	// Initialize variables
	string line = "";
	char letter = '\0';
	BTNode<char>* rootPtr = new BTNode<char>('\0');			// instantiates a node for use as the root
	masterRoot = rootPtr;									// sets this root to the master by pointer

	// Read in one line at a time
	while (fin >> line)
	{
		// First char of each line is the alphabetic letter
		letter = line[0];
		line = line.substr(1);								// remove this letter from rest of line (code)
		encodeMap.insert(pair<char, string>(letter, line));	// add the morse code to the encode map <char, morse>
		addNode(line, rootPtr, letter);						// adds this letter to the morsetree
	}
}

// Wrapper decode function
// takes the entire string of morse commands and tokenizes them and calls decode token on each
string morsetree::decode(string s)
{
	// Initialize variables
	string token = "";
	string message = "";

	// Keep removing one token at a time until empty
	while (s.length() != 0)
	{
		// Assumes if no space is found, this is the last token to be added
		if (s.find(" ") == string::npos)
		{
			token = s;										// set token to rest of string
			s = "";											// clear the input string to exit while loop
		}

		else if (s.find(" ") > 0)							// if a space was found
		{
			token = s.substr(0, s.find(" "));				// set token to start of string to first space
			s = s.substr(s.find(" ") + 1);					// set s to rest of string (minus the space)
		}

		// Call to decode this token and add it to the message
		message += decodeToken(masterRoot, token);
	}

	return message;											// Returns the entire message
}

// Decodes a single morse letter recursively
char morsetree::decodeToken(BTNode<char>* localRoot, string s)
{
	// if we've reached the desired node, return it's data (the desired letter)
	if (s == "")
		return localRoot->data; 

	// if first char is a . branch left, if _ branch right
	if (s[0] == '.')
		return decodeToken(localRoot->left, s.substr(1));
	else
		return decodeToken(localRoot->right, s.substr(1));
}

// Add a node to the binary tree
void morsetree::addNode(string s, BTNode<char>* localRoot, char c)
{ 
	// If we're down to a single character in the decode sequence this is where to add it
	// If we went one more layer down, we'd hit a null and raise an exception
	if (s.length() == 1)
	{
		// Declare a new node with this character (NEW operator!) -- otherwise lost when out of scope
		BTNode<char>* newNode = new BTNode<char>(c);	

		// If . branch left and add if _ branch right and add then return
		if (s[0] == '.')
			localRoot->left = newNode;
		else if (s[0] == '_')
			localRoot->right = newNode;
		return; 
	}

	// Otherwise we need to go another layer down into the tree
	else
	{
		if (s[0] == '.')
			return addNode(s.substr(1), localRoot->left, c);
		else if (s[0] == '_')
			return addNode(s.substr(1), localRoot->right, c);
	}

	return; // should never hit this
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

// Code from lectures to print the tree to verify implimented correctly
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

// Prints out each value in the map to verify integrity
void morsetree::printMap()
{
	// Declare iterator
	map<char, string>::iterator itr;

	// For each value, print character followed by morse equivalent
	for (itr = encodeMap.begin(); itr != encodeMap.end(); itr++)
		cout << itr->first << '\t' << itr->second << endl; 
}

// Encodes a message into morse code
string morsetree::encodeMessage(string s)
{
	string morse;	// Initialize a string

	// For each letter, find the character in the map and add its equivalent to the string followed by a space
	for (unsigned int i = 0; i < s.length(); i++)
	{
		morse += encodeMap.find(s[i])->second;
		morse += " "; 
	}

	// Return the message (in morse code)
	return morse; 
}