/*This is the node class used by the tree class.*/
class node {
public:
	node* L, * R;

	record* info;

	node();

	void sortedInsert(string,string);
	bool finder(string,record&);
};

node::node()
{
	L = NULL;
	R = NULL;
	info = NULL;
}

/*node::sortedInsert() sorts nodes as they're added by way of their
names.  This was a massive pain to try and print.  Instead of
building a print(), the commented-out cout statements were used
to prove that the tree was constructed correctly.*/
void node::sortedInsert(string name, string data)
{
	//cout << name << endl;
	if (info == NULL)
	{
		info = new record;
		info->name = name;
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
		L->sortedInsert(name, data);
	}
	else if (info->name < name)
	{
		//cout << "R test" << endl;
		if (R == NULL)
		{
			//cout << "R new test" << endl;
			R = new node;
		}
		R->sortedInsert(name, data);
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