/*The output file containts several iterations of this specific main
configuration, demonstrating the various operations as well as the
use of the erase() function.*/

enum eC { fail, success, overflow, underflow };

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

#include"bintree.h"

int main()
{
	srand(time(NULL));

	double totalAmount;

	tree information;

	information.grow(3);
	information.print();

	totalAmount = information.evaluate();
	cout << "\n\nThis tree amounted to: " << totalAmount << endl;

	information.erase();
	information.print();  //Attempting to print here results in nothing but an error code.

	cout << "\n\n\n\n------------Reset after E R A S E R--------------\n\n\n" << endl;

	information.grow(3);  //Growing here reuses the variable and creates a new tree.
	information.print();

	totalAmount = information.evaluate();
	cout << "\n\nThis tree amounted to: " << totalAmount << endl;	

}