#include<iostream>
using namespace std;

void change1(int a) {
	a = a + 2;
}


void change2(int& a) {
	a = a + 2;
}

void change3(int* a) {
	*a = *a + 2;
}


int main()
{ 
	int *p, *q;
	int array[10][10];
	int data[10];
	int* pData[10];
	int a, b, c, d;

	for (int i = 0; i < 10; i++)
	{
		data[i] = i + 1;
		p = &data[i];
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			array[i][j] = data[i];
			q = &array[i][j];
		}
	}

	cout << "p is: " << p << endl;
	cout << "*p is: " << *p << endl;

	p = data; //Assigns to first member of data.
	

	cout << "p is: " << p << endl;
	cout << "*p is: " << *p << endl;
	cout << "data first address is: " << &data << endl;

	p = data + 2;  //Moves along the data array by 2. 
	

	cout << "p is: " << p << endl;
	cout << "*p is: " << *p << endl;
	cout << "data second address is: " << &data[2] << endl;

	*p = 25;

	cout << "data second 2 is: " << data[2] << endl;

	cout << "p is: " << p << endl;
	cout << "*p is: " << *p << endl;
	cout << "q is: " << q << endl;
	cout << "*q is: " << *q << endl;

	q = p;

	cout << "p is: " << p << endl;
	cout << "*p is: " << *p << endl;
	cout << "q is: " << q << endl;
	cout << "*q is: " << *q << endl;

	int x = 10;
	cout << x << endl;
	change1(x);
	cout << x << endl;
	change2(x);
	cout << x << endl;
	change3(&x);
	cout << x << endl;

}

void adder(int*)
{

}