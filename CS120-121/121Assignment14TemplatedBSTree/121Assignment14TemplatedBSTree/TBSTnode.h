/*This is the node class used by the tree class.
TBSTnode stands for Templated Binary Search Tree node.*/

template <typename entrytype> //entrytype was used for ease of reading.

class node {
public:
	node<entrytype> * L, * R;

	bool rootcheck;  /*This variable serves exclusively for checking if root has any data in it
					 yet or not.  The nodes by themselves do not use this, but the tree will.*/

	entrytype info;

	node();

	void sortedInsert(node<entrytype>*); /*Sorts strings to the left or right of the current node.*/

	bool nInfixVisit(void(*visitor)(entrytype));  /*Applies functions from main to the entire tree.*/
	bool nFind(entrytype);  /*Checks if a specific entry is on the list.*/
	
};

template <typename entrytype>
node<entrytype>::node()
{
	rootcheck = 0;
	L = NULL;
	R = NULL;
}

/*node::sortedInsert() sorts nodes */
template <typename entrytype>
void node<entrytype>::sortedInsert(node<entrytype>* entrynode)
{	
	if (info > entrynode->info)
	{
		//cout << "L test" << endl;
		if (L == NULL)
		{
			L = entrynode;
		}
		else
		{
			L->sortedInsert(entrynode);
		}
	}
	else if (info < entrynode->info)
	{
		//cout << "R test" << endl;
		if (R == NULL)
		{
			R = entrynode;
		}
		else
		{
			R->sortedInsert(entrynode);
		}
	}
}

template <typename entrytype>
bool node<entrytype>::nInfixVisit(void(*visitor)(entrytype entry))
{
	bool chk = 0;

	if (L != NULL)
	{
		//cout << "R test" << endl;
		chk = chk + L->nInfixVisit(visitor);
	}

	visitor(info);
	chk = chk + 1;

	if (R != NULL)
	{
		//cout << "L test" << endl;
		chk = chk + R->nInfixVisit(visitor);
	}

	return chk;
}


template <typename entrytype>
bool node<entrytype>::nFind(entrytype entry)
{
	bool chk = 0;
	if (info == entry)
	{
		chk = 1;
		return chk;
	}

	if (L != NULL)
	{
		chk = chk + L->nFind(entry);
	}
	if (R != NULL)
	{
		chk = chk + R->nFind(entry);
	}

	return chk;
}