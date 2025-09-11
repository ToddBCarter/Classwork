/*This is the tree class that main() primarily
interacts with.  No extra effort was made to keep things
private from main().*/

class tree {
private:
	node* root;
public:
	tree();

	void insert(string,string);
	void find(string, record&);
};

tree::tree()
{
	root = new node;
}

/*Inserting new information is largely done by the nodes.*/
void tree::insert(string name, string data)
{
	root->sortedInsert(name, data);
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
