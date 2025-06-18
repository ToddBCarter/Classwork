#include<iostream>
#include<cstdlib>
using namespace std;


int main()
{
	int da = 10;

	int* p = &da;

	p = &da;

	*p = 8;
	
	int values[] = { 5, 10, 15, 20, 25 };
	int* a;
	a = (int*)values;

	//cout << values;

	//cout << a;
	//cout << &values;

	//cout << values[8];

	int b = 3 + 4 * 3;
	int c = 22 % 5;
	int d = 5 < 9;
	int e = 5 < 9 && 5 < 3;
	int f = 10 < 12 && 5;

	//cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;

	double z = 5.0 / 6.0 + (8 % 3) * 2.0 + 1;
	//z = (8 % 3);
	//z = 5 / 6; // +5;
	//z = (0 || 5 == 6 );
	//z = (0 || 5);
	z = (5 / 10) * 10.0;
	cout << z;

}
