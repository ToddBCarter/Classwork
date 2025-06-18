/*This is the main specified by the assignment.
Note: It is ONLY what was required by the assignment.
There is NO additional testing of functionality presented
in the output file.*/

enum eC {fail, success, overflow, underflow};
typedef int entrytype;

#include<iostream>
using namespace std;

#include"node.h"
#include"linked_list.h"

int main()
{
	linked_list integers;
	int x = 0;

	for (int i = 1; i <= 19; i += 2)
	{
		integers.append(i);
	}
	
	integers.pop();

	/*As was specified during lecture, both insert and remove
	use the first element of the list as location 0.  This means
	to insert the 4th item, you input a 3. Likewise, to remove
	the 7th item, you input a 6.*/
	integers.insert(3, 8);

	integers.remove(6);

	integers.append(22);

	x = integers.find(2);
	cout << "If there is a 2, this will be 1: " << x << endl;

	x = integers.find(15);
	cout << "If there is a 15, this will be 1: " << x << endl;

	integers.print();
	integers.reverseprint();

}