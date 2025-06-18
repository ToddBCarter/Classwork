/*This is the main for the trie of Assignment 15.

This program includes:

insert()
print()
find()
size()  Note - size() is called count().

for a total of (hopefully) 20 points.

Testing is done as simply as possible.*/

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

#include"triesnode.h"
#include"tries.h"

int main()
{
	trie tester;

	tester.insert("algernon");
	tester.insert("deuces");
	tester.insert("place");
	tester.insert("holder");
	tester.insert("goes");
	tester.insert("here");
	tester.insert("heehaw");
	tester.insert("harr");
	tester.insert("harrharr");
	tester.insert("alphabetical");
	tester.insert("platitude");
	tester.insert("placid");

	tester.print();

	cout << endl;

	string test = "harr";

	if (tester.find(test))
	{
		cout << "Found '" << test << "'!" << endl;
	}
	else
	{
		cout << "No unique string '" << test << "' here." << endl;
	}

	test = "harrh";

	if (tester.find(test))
	{
		cout << "Found '" << test << "'!" << endl;
	}
	else
	{
		cout << "No unique string '" << test << "' here." << endl;
	}

	test = "harrharr";

	if (tester.find(test))
	{
		cout << "Found '" << test << "'!" << endl;
	}
	else
	{
		cout << "No unique string '" << test << "' here." << endl;
	}

	test = "porkchopsandwiches";

	if (tester.find(test))
	{
		cout << "Found '" << test << "'!" << endl;
	}
	else
	{
		cout << "No unique string '" << test << "' here." << endl;
	}

	int uniqueStrings = tester.count();
	cout << "\nThe number of unique strings is: " << uniqueStrings << endl;


}