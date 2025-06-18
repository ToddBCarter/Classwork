/*This is the node class used by the tree class.*/
class node {
public:
	node* L, * R;

	record* info;

	node();

	void sortedInsert(string, string, string);
	bool finder(string, record&);

	int nTotalCounter(); /*Function to count total number of entries in the tree.*/
	int nSubCounter(string); /*Function to count number of instances of a given string*/
	int nTreeDepth();  /*Returns the depth of the tree.*/
	void nPrefixPrint();  /*Prints all entries in prefix order.*/
	void nListings(string);  /*Prints data connected to the passed string.*/
	int nErase(string, node*, int);  /*Deletes the requested node.  More or less.*/
};

node::node()
{
	L = NULL;
	R = NULL;
	info = NULL;
}

/*node::sortedInsert() sorts nodes as they're added by way of their
names.  As of assignment 12, species is also added, but not used for
the sorting.*/
void node::sortedInsert(string name, string spec, string data)
{
	//cout << name << endl;
	if (info == NULL)
	{
		info = new record;
		info->name = name;
		info->species = spec;
		info->data = data;
		//cout << "here's infoname: " << info->name << endl;
	}
	else if (info->name > name)
	{
		//cout << "L test" << endl;
		if (L == NULL)
		{
			L = new node;
			//cout << "L new test" << endl;
		}
		L->sortedInsert(name, spec, data);
	}
	else if (info->name < name)
	{
		//cout << "R test" << endl;
		if (R == NULL)
		{
			//cout << "R new test" << endl;
			R = new node;
		}
		R->sortedInsert(name, spec, data);
	}
}

/*Finder uses an internal system of returning 1s and 0s
in order to check for a name in the list.  This happens
in seven or less iterations on the given list.*/
bool node::finder(string name, record& data)
{
	int chk = 0;  /*Check variable that is passed up the
				  recursions as they collapse.  By adding the
				  returned value from each recursion, a final
				  1 or 0 will indicate if a match was found.*/

				  /*The name acts as a keyword in this if statement.
				  If the name is found, that means the current node is
				  the correct one, and its record is passed by reference up
				  to the record from main().*/
	if (name == info->name)
	{
		data = *info;
		chk = 1;
		return chk;
	}

	/*After checking the current node, the branches are
	checked individually.*/
	if (L != NULL && info->name > name)
	{
		chk = chk + L->finder(name, data);
	}
	else if (R != NULL && info->name < name)
	{
		chk = chk + R->finder(name, data);
	}

	if (chk >= 1)  //Just in case there's more than one.
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Very simply adds up the returned value of all nodes
in the tree and returns that total.*/
int node::nTotalCounter()
{
	int count = 0;

	if (info == NULL)  /*If the tree has nothing in it.*/
	{
		cout << "The tree depth is: 0" << endl;
	}
	else
	{
		count++;
		if (L != NULL)
		{
			count = count + L->nTotalCounter();
		}
		if (R != NULL)
		{
			count = count + R->nTotalCounter();
		}
	}
	return count;
}

/*This is the function to search for the number of entries that contain
a given substring.  In this case, it checks the name, the species, and
then uses the string function find() to check the remaining data.*/
int node::nSubCounter(string s)
{
	int count = 0;

	if (info->name.find(s) != -1 || info->species.find(s) != -1 || (info->data.find(s) != -1))
	{
		//cout << "test true" << endl;
		count++;
	}
	if (L != NULL)
	{
		if (L->info != NULL)
		{
			count = count + L->nSubCounter(s);
		}
	}
	if (R != NULL)
	{
		if (R->info != NULL)
		{
			count = count + R->nSubCounter(s);
		}
	}

	return count;
}

int node::nTreeDepth()
{
	int leftCount = 0;
	int rightCount = 0;

	if (info == NULL)
	{
		return 0;
	}
	if (L != NULL)
	{
		leftCount = L->nTreeDepth();
	}
	if (R != NULL)
	{
		rightCount = R->nTreeDepth();
	}

	if (rightCount > leftCount)
	{
		return rightCount + 1;
	}
	else
	{
		return leftCount + 1;
	}
}

void node::nPrefixPrint()
{
	cout << info->name << endl;
	
	if (L != NULL)
	{
		if (L->info != NULL)  //These nested if statements became necessary for the erase() function to work.
		{
			L->nPrefixPrint();
		}
	}
	if (R != NULL)
	{
		if (R->info != NULL)
		{
			R->nPrefixPrint();
		}
	}
	
}

/*This is the function that will print out all keys attached
to a specific substring.  The substring in this case is the
"species" that is extracted from each data line at the same
time as the names.  This function then takes the path of least 
resistance and prints out each name as it is found, thus 
providing a list.*/
void node::nListings(string s)
{
	if (info->name.find(s) != -1 || info->species.find(s) != -1 || (info->data.find(s) != -1))
	{
		cout << info->name << endl;
	}	
	
	if (L != NULL)
	{
		if (L->info != NULL)
		{
			L->nListings(s);
		}
	}
	if (R != NULL)
	{
		if (R->info != NULL)
		{
			R->nListings(s);
		}
	}
}

/*The delete function is some very ugly code that I have run out of time to clean up.
It is a hideous mess of if statements, and I am sorry.

The idea here is to find the node to be deleted using the name key, then to find a leaf
node, then swap them, and then remove the leaf node from the tree.  This more or less
worked out, but man, it's real real ugly.

How It Works:
The tree::erase() function passes over the string to find, a pointer to its own address,
and the starting place for a check integer.  The pointer to the root address is necessary,
as this function only looks at the left and right pointers, so to check if root is the
guilty party, the function must start there.
*/
int node::nErase(string n, node* root, int chk)
{
	node* temp = root;  /*temp serves as the address for the node to be deleted.
						This initialization catches the pass from the tree.  If root wasn't the one
						to be deleted, this should be a new node.  This is necessary, as
						there were further read access violations when trying to capture 
						the address of the current node using 'this.'*/
	if (info == NULL)
	{
		return 0;  /*Check to see if there's even anything in the tree.*/
	}

	if (L == NULL && R == NULL && chk != 0)  /*Checking for a leaf node while the recursions go.*/
	{
		if (temp->info != NULL)  /*This only will activate once the node to be deleted has been found.*/
		{
			node* innertemp = new node;

			innertemp->info = info;  /*Making the swap between the key node and the current node,
									 which should be a leaf node.*/
			info = temp->info;
			temp->info = innertemp->info;

			info = NULL; /*This effectively removes the leaf node from the tree.
						 The node is still there, but I've run out of time to try
						 and find that specific leak, so this prevents it from 
						 showing up when printed or searched.*/

			chk = 0;  /*This prevents innocent leaf nodes from being trimmed.  Probably.
					  Something is, at least, and I meant for this to be it.*/
		}
	}

	/*These if statements search for the node to be deleted.  Once found,
	they tick up the check variable (which might not be entirely necessary),
	and then assign temp to that node address.  This means that temp will now
	remember the address of the node to be deleted.*/
	if (L != NULL)
	{
		if (L->info->name == n)
		{
			temp = L;
			chk = 1;
		}
		chk = L->nErase(n, temp, chk);
	}

	if (R != NULL)
	{
		if (R->info->name == n)
		{
			temp = R;
			chk = 1;
		}
		chk = R->nErase(n, temp, chk);
	}	
	return chk;

}