// Daniel McNary
// Professor Kuhail
// CS 303
// 12/16/2015

#include <iostream>
#include "morsetree.h"
using namespace std;

int main()
{
	// Declare a morsetree to contain the encoding and decoding process
	morsetree morsetree; 

	// Enter a morse command with _ and . then will display the alphabetic decription
	cout << morsetree.decode("... ___ ...") << endl;

	// Enter a alphabetic command then the morse equivalent (encryption) will display
	cout << morsetree.encodeMessage("sos") << endl; 

	// Pause for user to read screen
	system("PAUSE");
	return 0; 
}