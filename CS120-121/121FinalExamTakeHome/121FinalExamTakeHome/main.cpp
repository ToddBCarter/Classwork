

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cctype>
using namespace std;

enum eC { fail, success, dividebyzero };  //Error codes used by fraction.h.

#include"species.h"
#include"TBSTnode.h"  /*Templated Binary Search Tree node.*/
#include"TBSTree.h"  /*Templated Binary Search Tree.*/


const int length = 25;

bool search(int[], int, int, int);

int main()
{
	//srand(time(NULL));
	//bool finder;  //finder is used to check the output from uses of find().


	specie dags, cats;

	string n = "Fidos";
	int p = 150;
	string s = "Safe";
	dags.set(n, p, s);
	

	n = "Fifis";
	p = 250;
	s = "Dangerous";
	cats.set(n, p, s);

	if (dags < cats)
	{
		cout << "true thing" << endl;
	}

	cout << "\n" << dags;




	int nS = 13;
	int daAr[length];

	for (int i = 0; i < length; i++)
	{
		daAr[i] = i;
	}


	if (search(daAr, 0, length, nS))
	{
		cout << nS << " is in the array." << endl;
	}
	else
	{
		cout << nS << " is not in the array." << endl;
	}

	nS = 200;

	if (search(daAr, 0, length, nS))
	{
		cout << nS << " is in the array." << endl;
	}
	else
	{
		cout << nS << " is not in the array." << endl;
	}
	



}

/*Turned in.*/
/*Binary Search function*/
bool search(int data[], int low, int high, int num)
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
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return false;
}

/*Turned in.*/
/*infix printing of nodes to be turned in:*/
/*
void bnode::infixprint()
{
	if (left != NULL)
	{
		left->infixprint();
	}
	cout << data << endl;
	if (right != NULL)
	{
		right->infixprint();
	}
}
*/

/*
Assume the strings (and only the strings) "cat", "cats", "cati", "bat", and "zebra" are stored in the tree.

How many nodes are there in the trie?

14?  Why not 13?

*/