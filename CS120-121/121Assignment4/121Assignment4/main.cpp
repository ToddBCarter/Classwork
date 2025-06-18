/*Assignment 4*/

/*For this assignment, main() is used exclusively for testing purposes.  
The results of the tests are in the text file.*/

#include<iostream>
using namespace std;
#include"fraction.h"

int main()
{
	fraction a1, a2;
	fraction b1(3, 4);
	int errorCode;

	cout << "Testing the multi-argument constructor: ";
	b1.print();
	cout << endl;

	cout << "Testing the set() function: ";
	a1.set(1,2);
	a1.print();
	cout << endl;

	cout << "Testing the dividebyzero error: ";
	errorCode = a1.set(5, 0);
	cout << "Error code is: " << errorCode << endl;

	cout << "\n\Fraction math testing begins here.\n" << endl;

	/*********************Multiplication**************************/
	cout << "Testing the fraction*fraction operator: ";
	/*The answer should be 1/20.*/
	a1.set(1, 2);
	a2.set(1, 10);
	a1.print();
	cout << " * ";
	a2.print();
	cout << " = ";
	a1 = a1.operator*(a2);
	a1.print();
	cout << "\n";

	cout << "Testing the fraction*integer operator:  ";
	/*The answer should be 10/20.  However, because of reducifier(),
	the displayed answer should be 5.*/
	a1.set(1, 2);
	a1.print();
	cout << " * 10 = ";
	a1 = a1.operator*(10);
	a1.print();
	cout << "\n";

	cout << "Testing the integer*fraction operator:  ";
	/*The answer should be 10/20.  However, because of reducifier(),
	the displayed answer should be 5.*/
	a1.set(1, 2);
	cout << "10 * ";
	a1.print();
	cout << " = ";
	a1 = operator*(10, a1);
	a1.print();
	cout << "\n";

	/*++++++++++++++++++++++Addition++++++++++++++++++++++++++++*/
	cout << "Testing the fraction+fraction operator: ";
	/*The answer should be 12/20.  The reducifier() makes it 3/5.*/
	a1.set(1, 2);
	a1.print(); 
	cout << " + ";
	a2.print();
	cout << " = ";
	a1 = a1.operator+(a2);
	a1.print();
	cout << "\n";

	cout << "Testing the fraction+integer operator:  ";
	/*The answer should be 21/2.*/
	a1.set(1, 2);
	a1.print();
	cout << " + 10 = ";
	a1 = a1.operator+(10);
	a1.print();
	cout << "\n";

	cout << "Testing the integer+fraction operator:  ";
	/*The answer should be 21/2.*/
	a1.set(1, 2);
	cout << "10 + ";
	a1.print();
	cout << " = ";
	a1 = operator+(10, a1);
	a1.print();
	cout << "\n";

	/*---------------------Subtraction--------------------------*/
	cout << "Testing the fraction-fraction operator: ";
	/*The answer should be 8/20.  This should reduce down to 2/5.*/
	a1.set(1, 2);
	a1.print();
	cout << " - ";
	a2.print();
	cout << " = ";
	a1 = a1.operator-(a2);
	a1.print();
	cout << "\n";

	cout << "Testing the fraction-integer operator:  ";
	/*The answer should be -19/2.*/
	a1.set(1, 2);
	a1.print();
	cout << " - 10 = ";
	a1 = a1.operator-(10);
	a1.print();
	cout << "\n";

	cout << "Testing the integer-fraction operator:  ";
	/*The answer should be 19/2.*/
	a1.set(1, 2);
	cout << "10 - ";
	a1.print();
	cout << " = ";
	a1 = operator-(10, a1);
	a1.print();
	cout << "\n\n\n\n";



	a1.set(90, 8000);
	a1.reducifier();
	a1.print();
}