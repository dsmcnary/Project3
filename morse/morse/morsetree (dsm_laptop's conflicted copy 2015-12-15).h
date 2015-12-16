#pragma once
#include <string>
#include "BTNode.h"
#include "Binary_Tree.h"
using namespace std; 

class morsetree
{
public:
	morsetree();
	string decode(string s);
	~morsetree();
	void findNode(string s, Binary_Tree<char> tree, char c); 
	void addNode(char c);

private:
	void error(string s);
	BTNode<char>* masterRoot; 
	Binary_Tree<char> master; 
};