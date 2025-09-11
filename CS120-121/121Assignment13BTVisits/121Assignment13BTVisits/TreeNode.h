/*This is the node class used by the tree class.*/

class node {
public:
	node* L, * R;

	record* info;

	node();

	/*Assignment 11 functions.*/
	void sortedInsert(string, string, string); /*Sorts strings to the left or right of the current node.*/

	/*Assignment 12 functions.*/
	void nInfixPrint();  /*Prints all entries in prefix order.*/

	/*Assignemnt 13 functions.  They are at the bottom of the page.*/
	bool nVisit(void (*around)(record*));  /*Visits a function on every node.*/
	bool nKeyVisit(void (*around)(record*), string); /*Visits a function on a specific key.*/
	bool nDataVisit(void (*around)(record*), string); /*Visits a function on nodes with a specific substring of data.*/
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

/*While testing, I noted Zucker does not show up on a prefix list.
He is affected by all other functions, he's counted, you can call up
his name, he even is affected by the capitalization.
But he will not print.
There is only one answer.
Prefix printing is anti-octopus.
(Or I was wrong.)
(He shows up fine when testing with infix.)*/
void node::nInfixPrint()
{
	if (L != NULL)
	{
		L->nInfixPrint();
	}
	cout << info->name << endl;
	if (R != NULL)
	{

		R->nInfixPrint();
	}
}

/*Having been passed the visitor pointer from the tree,
the nodes are now able to handle traversal by way of recursion.
For the standard visit function, the visitor is applied to 
all nodes.
The chk variable is used to report success or failure.*/
bool node::nVisit(void (*visitor)(record* r))
{
	bool chk = 0; /*Declared the check variable.*/
	if (info == NULL)
	{		
		return chk; /*Always return check to give an accurate report.*/
	}
	if (R != NULL)
	{
		if (R->info != NULL)
		{
			chk = chk + R->nVisit(visitor);
		}
	}
	if (L != NULL)
	{
		if (L->info != NULL)
		{
			chk = chk + L->nVisit(visitor);
		}
	}
	visitor(info);
	chk = 1;
	return chk;
}

/*This visitor runs a check for the string that has been passed
from the tree against the name string stored in the record.
As with nVisit, the chk variable is used to report success or failure.*/
bool node::nKeyVisit(void (*visitor)(record* r), string n)
{
	bool chk = 0;
	if (R != NULL)
	{
		if (R->info != NULL)
		{
			chk = chk + R->nKeyVisit(visitor, n);
		}
	}
	if (L != NULL)
	{
		if (L->info != NULL)
		{
			chk = chk + L->nKeyVisit(visitor, n);
		}
	}
	if (info->name == n)  /*Testing if the correct name has come up.*/
	{
		visitor(info);
		chk = 1;
		return chk;
	}
	return chk; 
}

/*nDataVisit will check all the data from each node against a given substring, 
and perform the visitor function only if it finds a match. A check 
variable is again used to report success or failure.*/ 
bool node::nDataVisit(void (*visitor)(record* r), string n)
{
	bool chk = 0;
	if (L != NULL)
	{
		if (L->info != NULL)
		{
			chk = chk + L->nDataVisit(visitor, n);

		}
	}
	if (R != NULL)
	{
		if (R->info != NULL)
		{
			chk = chk + R->nDataVisit(visitor, n);
		}
	}
	if (info->name.find(n) != -1 || info->species.find(n) != -1 || (info->data.find(n) != -1))
	{
		visitor(info);
		chk = 1;
		return chk;
	}
	return chk;
}