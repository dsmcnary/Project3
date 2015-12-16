#pragma once
#include <string>
#include "BTNode.h"
using namespace std; 

class morsetree
{
public:
	morsetree();
	string decode(string s);
	void addNode(string s, BTNode<char>* localRoot, char c);
	~morsetree();

private:
	void error(string s);
	BTNode<char>* masterRoot; 
};