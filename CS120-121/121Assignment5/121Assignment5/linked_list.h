/*The linked list class is fairly basic.
Each node will store two addresses, one for
next and one for the previous.  A recursive
function is used to supplement the find()
function.*/

class node
{
private:

public:
	node();
	node(entrytype, node*);
	node* next;
	node* prev;
	node setprev(node* n) { prev = n; }
	entrytype info;
	bool finder(entrytype);
	void print();
};

node::node()
{
	info = 0;
	next = NULL;
}

node::node(entrytype num, node* ent = NULL)
{
	info = num;
	next = ent;
}

void node::print()
{
	if (next != NULL)
	{
		next->print();
		cout << info << endl;
	}
}

/*Finder does the heavy lifting in searching
for a matching number.  The system of linking
of the list means that only members will
have addresses in next, and non-members will
have NULL.*/
bool node::finder(entrytype num)
{	
	int x = 0;

	if (next != NULL)
	{
		if (info == num)
		{
			return true;
		}
		else
		{
			next->finder(num);
		}
	}
	else
	{
		return false;
	}
}