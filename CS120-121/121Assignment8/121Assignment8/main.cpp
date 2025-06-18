/*This code uses a double linked list taken from a previous assignment with the new function,
inserted_into_Sorted(), which is a sorted insertion into an already-sorted list.  The original
find() function was also renamed linear_search().  The double linking relies on *next as well as
another pointer *prev in order to keep track of the list from both directions, and the linked
list itself keeps track of the *top and *bottom of the list.

A new function was added to main called binary_Search(), which is a binary searching algorithm
that will search an array by a divide and conquer method.

Both the linked list and the array have a length of 3000, and each value is random 0 to 9999.
The array is sorted using the selection() algorithm taken from the previous assignment.

The Insertion Sort is a function called insert_into_Sorted().  It is called with the number of
items to be inserted into the list.

The Linear Search is called linear_Search().  It is called with the number to be searched for.

The Binary Search is called binary_Search().  It is called with the array, the upper and lower
bounds of the array, and the number to be searched for.  The upper and lower bounds take
advantage of being local variables, allowing them to be changed within the scope of the function
in order to temporarily divide the array.*/

enum eC { fail, success, overflow, underflow };
typedef int entrytype;

#include<iostream>
#include<ctime>
#include<chrono>
#include<fstream>
using namespace std;

#include"node.h"
#include"linked_list.h"

bool binary_Search(int[], int, int, int);

double selection(int[], int);  //This function is from the previous assignment and is used to sort the array.
void print(int[], int);

const int leng = 3000;

int main()
{
	srand(time(NULL));

	linked_list integers;
	int stuff[leng];
	int x = 0;


	/*========================================Testing Insertion Sort===================================*/

	cout << "Testing Insertion Sort into an empty list: " << endl;
	integers.insert_into_Sorted(15);
	integers.print();
	cout << "Testing Insertion Sort into the same list: " << endl;
	integers.insert_into_Sorted(15);
	integers.print();



	/*==========================================Testing Binary Search===================================*/

	for (int i = 0; i < leng; i++)
	{
		stuff[i] = rand() % 10000;
	}
	selection(stuff, leng);


	auto start = chrono::steady_clock::now();  //All measuring of time happens only while the search is running.

	x = binary_Search(stuff, 0, leng, 50);

	auto end = chrono::steady_clock::now();

	cout << "\n\nBinary search took " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns to complete." << endl;
	cout << "If there is a 50 on the array, this will be one: " << x << endl;



	/*==========================================Testing Linear Search===================================*/

	integers.clear(); //If you have a clear(), might as well use it.
	integers.insert_into_Sorted(3000);  //Using insertion sort to create a pre-sorted list.

	start = chrono::steady_clock::now();

	x = integers.linear_Search(50);

	end = chrono::steady_clock::now();

	cout << "Linear search took " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns to complete." << endl;
	cout << "If there is a 50 on the linked list, this will be 1: " << x << endl;


	/*===========Gathering testing data using a for loop on the previous two methods==================*/

	for (int u = 0; u < 50; u++)
	{
		for (int i = 0; i < leng; i++)
		{
			stuff[i] = rand() % 10000;
		}
		selection(stuff, leng);

		auto start = chrono::steady_clock::now();

		x = binary_Search(stuff, 0, leng, 1);

		auto end = chrono::steady_clock::now();

		cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "   ";



		integers.clear();
		integers.insert_into_Sorted(3000);  

		start = chrono::steady_clock::now();

		x = integers.linear_Search(1);

		end = chrono::steady_clock::now();

		cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
	}
}

bool binary_Search(int data[], int low, int high, int num)
{
	int mid = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (data[mid] == num)
		{
			return true;
		}

		if (data[mid] > num)
		{
			high = mid - 1;  //Since high and mid are local variables, changing them does not affect main().
		}
		else
		{
			low = mid + 1;
		}
	}
	return false;
}

double selection(int data[], int len)
{
	bool sorted = true;

	int temp = 0;
	int indexer = 0;
	int smallest = data[0];  

	do {
		sorted = true;

		for (int j = 0; j < len; j++)
		{
			smallest = data[j];
			for (int i = j + 1; i < len; i++)
			{
				if (smallest > data[i])
				{
					smallest = data[i];
					indexer = i;
				}
			}

			if (data[j] > data[indexer])
			{
				temp = data[j];
				data[j] = data[indexer];
				data[indexer] = temp;
				sorted = false;
			}
		}
	} while (sorted == false);
	return indexer;
}

void print(int data[], int len)
{
	for (int j = 0; j < (len); j++)
	{
		cout << data[j] << " ";
	}
	cout << endl;
}