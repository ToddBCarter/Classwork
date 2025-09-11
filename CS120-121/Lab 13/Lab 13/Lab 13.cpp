#include<iostream>
using namespace std;
#include"linkedlist.h"

int main() {
	linkedlist animals;
	node* p;
	string dead;
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
	p->setdata("horse");
	animals.push(p);

	p = new node();
	p->setdata("pigeon");
	animals.push(p);

	animals.print();
	animals.reverseprint();

	dead = animals.pop();

	cout << "\nYou killed an endangered: " << dead << "\n";
	cout << "Proof of your crime: " << "\n\n";

	animals.print();
	animals.reverseprint();

}
