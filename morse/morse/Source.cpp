// Daniel McNary
// Professor Kuhail
// CS 303
// 12/16/2015

#include <iostream>
#include "morsetree.h"
#include "BTNode.h"
using namespace std;

int main()
{
	morsetree morsetree; 

	cout << morsetree.decode("_.. __.") << endl;
	cout << morsetree.encodeMessage("ac") << endl; 

	system("PAUSE");
	return 0; 
}