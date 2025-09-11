/*main() for assignment 14.  There is a slight Saturday Night Live theme.

The two classes that have been used are the fraction.h class from Assignment 4 and a new
class called "birthday.h" which checks and stores birthdays.

As always, formatting of all code is kept spacious so as to make for easy reading.

Note:  find() is only tested on the fraction tree and the string tree, as the other two
trees, birthdays and integers, are randomly generated and there is no guarantee that
there will be a specific entry on the list.*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

enum eC { fail, success, dividebyzero };  //Error codes used by fraction.h.

#include"fraction.h"
#include"birthday.h"
#include"TBSTnode.h"  /*Templated Binary Search Tree node.*/
#include"TBSTree.h"  /*Templated Binary Search Tree.*/


/*Prototypes for the functions that are passed using visit().
All uses of visit() will simply print out the list, one way or another.
No other functionality is used by way of visit().*/
void fractionPrint(fraction);
void birthdayPrint(birthday);
void intPrint(int);
void stringPrint(string);

int main()
{
	srand(time(NULL));
	bool finder;  //finder is used to check the output from uses of find().

/*--------------First testing a tree of fractions: ------------------------------------------*/
	cout << "\n-----------Testing fractions-------------" << endl;
	fraction f1;
	tree<fraction> t1;

	/*Conjuring up a list of fractions.  This generates some errors that are printed out,
	which goes to indicate the fraction class is working correctly.*/
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			f1.set(i, j);
			t1.insert(f1);
		}
	}

	/*Testing the visit function.*/
	void (*visitor1)(fraction);
	visitor1 = fractionPrint;
	t1.infixVisit(visitor1);

	/*Testing a successful find.*/
	f1.set(1, 2);
	finder = t1.find(f1);
	cout << "\nIf the fraction 1/2 is on the list, this will be 1: " << finder << endl;

	/*Testing an unsuccessful find.*/
	f1.set(23, 3);
	finder = t1.find(f1);
	cout << "\nIf the fraction 23/3 is on the list, this will be 1: " << finder << endl;


/*---------------Next, testing a tree of birthdays: ------------------------------------------*/
	cout << "\n-----------Testing birthdays-------------" << endl;
	birthday b1;
	tree<birthday> t2;
	
	/*Conjuring up some random birthdays.*/
	for (int i = 0; i < 20; i++)
	{
		/*These numbers were chosen due to occasionally generating errors,
		indicating the birthday class is working.  These errors aren't very
		informative since the list is nonsense anyway, they are only intended
		to indicate a change occurred.*/
		int day = rand() % 31 + 1;
		int mon = rand() % 12 + 1;
		int yea = rand() % 122 + 1900;  /*Oldest human was ~120 years old.*/

		b1.set(day, mon, yea);
		t2.insert(b1);
	}

	/*Testing the visit function.*/
	void (*visitor2)(birthday);
	visitor2 = birthdayPrint;
	t2.infixVisit(visitor2);

	/*Testing find.
	Note:  Since the birthdays are randomly generated, this will very rarely be true.*/
	b1.set(17, 11, 1944);
	finder = t2.find(b1);
	cout << "\nIf Lorne Michael's birthday is on the list, this will be 1: " << finder << endl;

	
/*----------------Next, testing a tree of strings: -------------------------------------------*/
	cout << "\n-----------Testing strings-------------" << endl;
	string s1;
	tree<string> t3;

	/*--Plays sax intro--*/
	t3.insert("Tina Fey"); 	
	t3.insert("David Spade");
	t3.insert("Adam Sandler");
	t3.insert("Will Ferrell");
	t3.insert("Eddie Murphy");
	t3.insert("Chris Farley");
	t3.insert("Bill Hartman");
	t3.insert("Dan Aykroyd");
	t3.insert("Jim Belushi");
	t3.insert("Amy Poehler");
	t3.insert("Bill Hader");
	t3.insert("Mike Myers");
	t3.insert("Robert Downey Jr.");
	t3.insert("Kenan Thompson");
	/*It's Saturday Niiiiiight!*/

	/*Testing visit.*/
	void (*visitor3)(string);
	visitor3 = stringPrint;
	t3.infixVisit(visitor3);

	/*Testing a successful find.*/
	s1 = "Dan Aykroyd";
	finder = t3.find(s1);
	cout << "\nIf Dan Aykroyd is on the list, this will be 1: " << finder << endl;

	/*Testing an unsuccessful find, as Kenan and Kel will likely never reunite.*/
	s1 = "Kel Mitchell";
	finder = t3.find(s1);
	cout << "\nIf Kel Mitchell is on the list, this will be 1: " << finder << endl;


/*----------------Last, testing a tree of integers: ------------------------------------------*/
	cout << "\n-----------Testing integers-------------" << endl;
	int i1;
	tree<int> t4;

	/*Inserting some random integers.*/
	for (int i = 0; i < 15; i++)
	{
		i1 = rand() % 1000;
		t4.insert(i1);		
	}

	/*Testing visit by printing the list of integers.*/
	void(*visitor4)(int);
	visitor4 = intPrint;
	t4.infixVisit(visitor4);

	/*Testing find.  Note, since the list is randomly generated, this will almost always fail.*/
	i1 = rand() % 1000;
	finder = t4.find(i1);
	cout << "\nIf " << i1 << " is on the list, this will be 1: " << finder << endl;

}

/*Individual functions for the various classes have been written 
to be passed using visit. These functions are not universally 
applicable, but without some form of clarification, this is 
assumed the correct approach.*/
void fractionPrint(fraction f)
{
	f.print();
	cout << endl;
}

void birthdayPrint(birthday b)
{
	b.print();
	cout << endl;
}

void intPrint(int i)
{
	cout << i << endl;
}

void stringPrint(string s)
{
	cout << s << endl;
}