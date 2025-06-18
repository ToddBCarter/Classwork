/*Assignment 3
CS 121-01
2-3-2022*/

/*This is the main() for the queue class.  This main consists
almost entirely of testing to produce the various error codes
and demonstrate the class functions.*/

#include<iostream>
using namespace std;
#include"queue.h"

int main()
{
	queue theList;
	eC x;
	
	cout << "The testing: " << endl;
	cout << "\n" << endl;

	/*--------------------------------------------------------------------*/

	/*The code is broken into testing sections. This first
	section is testing the underflow error code from the pop()
	function.  By only pushing two elements and then popping
	three, this results in an underflow(3) error code.*/
	x = theList.push(5);
	cout << "The first push is: " << x << endl;
	x = theList.push(12);
	cout << "The second push is: " << x << endl;
	
	x = theList.pop();
	cout << "This should be zero: " << x << endl;
	x = theList.pop();
	cout << "This should be zero: " << x << endl;
	x = theList.pop();
	cout << "This number should be three: " << x << endl;
	
	cout << "\n\n" << endl;


	/*--------------------------------------------------------------------*/

	/*This second section is testing the overflow
	function of push().  The final push returns an overflow
	error code.  This is followed by a print() to show what
	is currently being stored in the queue.  Since the final
	value is an overflow, it is not on the list.*/
	x = theList.push(120);
	cout << "This should be zero: " << x << endl;
	x = theList.push(12);
	cout << "This should be zero: " << x << endl;
	x = theList.push(3);
	cout << "This should be zero: " << x << endl;
	x = theList.push(15);
	cout << "This should be zero: " << x << endl;
	x = theList.push(230);
	cout << "This should be zero: " << x << endl;
	x = theList.push(3827365);
	cout << "This should be two: " << x << endl;

	theList.print();

	cout << "\n" << endl;


	/*--------------------------------------------------------------------*/

	/*The next section is testing the functionality
	of the circular array.  They begin by popping all
	elements currently on the array, then pushing more
	and popping more.  If the code is working correctly,
	error codes will be as expected and the final print
	will be 980 56.*/
	for (int i = 0; i < 5; i++)
	{
		x = theList.pop();
		cout << "Error code on these pops should be zero: " << x << endl;
	}

	cout << "\n";

	for (int i = 0; i < 5; i++)
	{
		x = theList.push(i);
		cout << "Error code on these pushes should be zero: " << x << endl;
	}

	/*A quick print to check that the array is loaded correctly.*/
	theList.print();

	for (int i = 0; i < 5; i++)
	{
		x = theList.pop();
		cout << "Error code on pops here should be zero: " << x << endl;
	}

	/*This print is included to prove it will not print anything when
	the array is empty.*/
	theList.print();

	x = theList.push(980);
	cout << "Error code down here should be zero: " << x << endl;
	x = theList.push(56);
	cout << "Error code down here should be zero: " << x << endl;

	theList.print();

	cout << "\n";


	/*--------------------------------------------------------------------*/

	/*This short testing section is for the front() function.  Here it will
	replace the 980 in the list with 1000, which is demonstrated
	by print().*/

	theList.front(1000);
	theList.print();


	/*--------------------------------------------------------------------*/

	/*Lastly testing the empty() function.  It first tests while two elements still
	remain, then pops them off and tests the empty array.*/
	int y = theList.empty();
	cout << "If the queue has elements, this will be zero: " << y << endl;
	
	theList.pop();
	theList.pop();

	cout << "The last two elements have been removed." << endl;
	y = theList.empty();
	cout << "If the queue does not have elements, this will be one: " << y << endl;

}