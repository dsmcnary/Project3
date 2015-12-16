// Daniel McNary
// Professor Kuhail
// CS 303
// 12/16/2015

#pragma once
#include <string>
#include "BTNode.h"
#include <map>
using namespace std; 

class morsetree
{
public:
	morsetree();
	string decode(string s);
	char decodeToken(BTNode<char>* localRoot, string s);
	void addNode(string s, BTNode<char>* localRoot, char c);
	~morsetree();
	string morsetree::pre_order(const BTNode<char>* local_root) const; 
	void printMap(); 
	string encodeMessage(string s); 

private:
	void error(string s);
	BTNode<char>* masterRoot; 
	map<char, string> encodeMap; 
};