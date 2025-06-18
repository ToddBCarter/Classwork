/*Todd Carter
Section 1
Assignment 2 pt 2
1-25-2022*/

/*This is a simple program that takes a short input string and
uses three stacks to determine if parantheses, brackets, and angle
brackets have been paired correctly.  The code will take the input
using getline() to include whitespaces, push any open brackets to
the stack, then for each closed bracket encountered, check the top
and pop it off if there's a match.  If the stack is empty at the end,
then all brackets were paired correctly.*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	string inp;
	stack<char> bStk;
	char x;

	cout << "Come on then, show us your parentheses.\n" << endl;
	getline(cin, inp);

	for (int i = 0; i < inp.length(); i++)
	{
		x = inp[i];			

		if (x == '{' || x== '(' || x == '[')
		{
			bStk.push(x);
		}
		else
		{
			if (x == ')')
			{
				if (bStk.top() == '(')
				{
					bStk.pop();
				}
				else
				{
					cout << "Is that an unmatched closed parenthesis or are you just happy to see me...  Okay, not happy." << endl;
					return 0;
				}
			}
			if (x == ']')
			{
				if (bStk.top() == '[')
				{
					bStk.pop();
				}
				else
				{
					cout << "Is that an unmatched closed square bracket or are you just happy to see me...  Okay, not happy." << endl;
					return 0;
				}
			}
			if (x == '}')
			{
				if (bStk.top() == '{')
				{
					bStk.pop();
				}
				else
				{
					cout << "Is that an unmatched closed angle bracket or are you just happy to see me...  Okay, not happy." << endl;
					return 0;
				}
			}
		}
	}

	if (bStk.empty())
	{
		cout << "Alright, good nuff.  Go on, off with you, then." << endl;
	}
	else
	{
		cout << "Oy!  That's unmatched open brackets in there!  Alright, you bugger, you're nicked!\n" << endl;
	}
}