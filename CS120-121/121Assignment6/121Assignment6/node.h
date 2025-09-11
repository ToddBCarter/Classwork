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
	void reverseprint();
	node* getprev() { return prev; }
	eC clearer();
};

node::node()
{
	info = 0;
	next = NULL;
	prev = NULL;
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

/*Reverse printing is easy with a double-
linked list.*/
void node::reverseprint()
{
	if (prev != NULL)
	{
		prev->reverseprint();
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

/*Clearer is the recursive function used by
linked_list to delete the entire list.*/
eC node::clearer()
{
	if (next != NULL)
	{
		next->clearer();
		delete next;
	}
	return success;
}