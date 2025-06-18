/*This is the tree class that main() primarily
interacts with.  No extra effort was made to keep things
private from main().*/

class tree {
private:
	node* root;
public:
	tree();

	void insert(string, string, string);
	void find(string, record&);

	int totalCounter(); /*Function to count total number of entries in the tree.*/
	int subCounter(string); /*Function to count number of instances of a given string in the tree.*/
	int treeDepth();  /*Returns the depth of the tree.*/
	void prefixPrint();  /*Prints all entries in prefix order.*/
	void listings(string);  /*Prints data connected to the passed string.*/
	void erase(string);  /*Deletes the requested node.*/

};

tree::tree()
{
	root = new node;
}

/*Inserting new information is largely done by the nodes.*/
void tree::insert(string name, string spec, string data)
{
	root->sortedInsert(name, spec, data);
}

/*tree::find() mostly passes the information along to node::finder(),
but it also does the printing after finder() has been performed.*/
void tree::find(string name, record& info)
{
	bool chk = 1;

	chk = root->finder(name, info);

	if (chk == true)
	{
		cout << "\nFound: \n" << info.name << " " << info.data << endl;
	}
	else
	{
		cout << "\nFound nothing.\n" << endl;
	}
}


int tree::totalCounter()
{
	int count = root->nTotalCounter();

	cout << "The tree size is: " << count << endl;

	return count;
}

int tree::subCounter(string s)
{	
	int count = -5;
		
	count = root->nSubCounter(s);

	cout << "There are: " << count << " instances of '" << s << "' in the tree." << endl;

	return count;
}

int tree::treeDepth()
{
	int depth = -5;
		
	depth = root->nTreeDepth();

	cout << "The tree is " << depth << " levels deep." << endl;

	return depth;
}

void tree::prefixPrint()
{
	root->nPrefixPrint();
}

void tree::listings(string species)
{
	root->nListings(species);
}

void tree::erase(string n)
{
	node* temp = new node;

	/*First checking it root has anything to delete.*/
	if (root->info == NULL)
	{
		cout << "Nothing to delete." << endl;
		return;
	}

	/*Then check if root is the one to be deleted.
	If it is, then its address is passed to the node function,
	and its record *info will be replaced.*/
	if (root->info->name == n)
	{
		temp = root;
	}

	root->nErase(n, temp, 0);

}