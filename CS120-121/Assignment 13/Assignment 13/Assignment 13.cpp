#include<iostream>
using namespace std;
#include"linkedlist.h"

int main() {
	linkedlist animals;
	node* p;
	int length = 0, found = -10;
	string name;

	p = new node();
	p->setdata("cat");
	animals.push(p);

	p = new node();
	p->setdata("dog");
	animals.push(p);

	p = new node();
	p->setdata("unicorn");
	animals.push(p);

	p = new node();
	p->setdata("ocelot");
	animals.push(p);

	p = new node();
	p->setdata("dancing bear");
	animals.push(p);

	/*Here is the appended node.*/
	p = new node();
	p->setdata("buggalo");
	animals.append(p);

	/*The returned length from count().*/
	length = animals.count();
	cout << "Length is: " << length << endl;

	/*Here is the use of find().*/
	found = animals.find("dog");

	/*This if chain checks whether or not the inputted
	name was already on the list or not.*/
	if (found == 1)
	{
		cout << "That's on the list!" << endl;
	}
	else if (found == 0)
	{
		cout << "That's not on the list." << endl;
	}
	else if (found == -10)
	{
		cout << "Something went wrong!" << endl;
	}
	else
	{
		cout << "Something went VERY wrong!" << endl;
	}

	name = animals.get(3);
	cout << "The third animal is: " << name << endl;

	animals.print();
}
