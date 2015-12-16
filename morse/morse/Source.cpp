#include <iostream>
#include "morsetree.h"
#include "BTNode.h"
using namespace std;

int main()
{
	morsetree morsetr; 

	//cout << morsetr.decode("... ___ ...") << endl;

	/*
	BTNode<char> root('\0', NULL, NULL);
	BTNode<char> leftNode('e', NULL, NULL);
	BTNode<char> rightNode('f', NULL, NULL);

	BTNode<char> leftNode1('g', NULL, NULL);
	BTNode<char> rightNode1('h', NULL, NULL);

	BTNode<char> leftNode2('i', NULL, NULL);
	BTNode<char> rightNode2('j', NULL, NULL);


	root.left = &leftNode;
	root.right = &rightNode;

	root.left->left = &leftNode1;
	root.left->right = &rightNode1;

	root.right->left = &leftNode2;
	root.right->right = &rightNode2;

	cout << root.data << endl
		<< root.left->data << endl
		<< root.right->data << endl; 

	cout << root.left->left->data << endl
		<< root.left->right->data << endl;

	cout << root.right->left->data << endl
		<< root.right->right->data << endl;*/

	system("PAUSE");
	return 0; 
}