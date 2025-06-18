/*As requested in the assignment, main() consists
of the various actions that demonstrate the functions
of the linked list queue.  main() has ONLY the
functionality as requested by the assignment, and does
not test all aspects of the functions.  The output
demonstrates main(), not a full testing range.*/

enum eC { fail, success, overflow, underflow };
typedef int entrytype;

#include<iostream>
using namespace std;

#include"linked_list.h"
#include"queue.h"

int main()
{
	queue integers, testing;
	int x = 0;
	int y = 26;

	cout << "Error codes are: " << endl;
	cout << "0 - Fail" << endl;
	cout << "1 - Success" << endl;
	cout << "2 - overflow" << endl;
	cout << "3 - underflow" << endl;
	cout << "\n" << endl;

	for (int i = 0; i < 399; i += 2)
	{
		integers.append(i);
	}

	integers.front(x);
	cout << "The first element in the queue is: " << x << endl;

	integers.pop();
	integers.pop();

	x = integers.find(8);
	cout << "If there is an 8 in the queue, this will be 1: " << x << endl;

	x = integers.find(200);
	cout << "If there is a 200 in the queue, this will be 1: " << x << endl;

	x = integers.size();
	cout << "The current size of the queue is: " << x << endl;

	for (int i = 0; i < 10; i++)
	{
		integers.pop();
	}
	x = integers.size();
	cout << "The size of the queue after 10 pops is: " << x << endl;

	integers.front(x);
	cout << "The new first element in the queue is: " << x << endl;
}