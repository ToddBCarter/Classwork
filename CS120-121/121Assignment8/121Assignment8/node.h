class node
{
private:

public:
	node();
	node(entrytype, node*);

	node* next;
	node* prev;
	entrytype info;

	node setprev(node* n) { prev = n; }
	void print();
	void reverseprint();
	node* getprev() { return prev; }
	eC cleaner();

	bool inserter(entrytype);  //This function is relevant to assignment 8.
	bool finder(entrytype);  //As is this one.  Both are towards the bottom.
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

void node::reverseprint()
{
	if (prev != NULL)
	{
		prev->reverseprint();
		cout << info << endl;
	}
}

eC node::cleaner()
{
	if (next != NULL)
	{
		next->cleaner();
		delete next;
	}
	return success;
}

/*This is the essence of the linear search.  It very simply
checks through the list one entry at a time until it finds
a match.*/
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

/*This is the brains behind the insertion sort.
It creates a new node that is given the new user value,
then moves up the list from *bottom looking for values
less or greater/equal.  It then swaps around the next and
prev values, which integrates the new node into the list.*/
bool node::inserter(entrytype num)
{
	int x = 0;

	node* temp = new node;
	temp->info = num;

	if (next != NULL)
	{
		if (temp->info < info)
		{
			delete temp;
			next->inserter(num);
		}
		else
		{
			temp->prev = prev;  //In order to maintain the double-link, both *next and *prev are updated.
			temp->next = prev->next;
			prev->next = temp;
			prev = temp;
			return true;
		}
	}
	else
	{
		return false;
	}
}