class trie
{
private:
	node* root;
public:
	trie();

	void insert(string);  /*Insert function.*/
	void print();  /*Prints the entire trie.*/
	bool find(string);  /*Returns a boolean value if a certain string is found.*/
	int count();  /*Returns the number of unique, complete strings in the trie.*/
};

trie::trie()
{
	root = new node;
}

void trie::insert(string s)
{
	root->nInsert(s);
}

void trie::print()
{
	root->nPrint();
}

bool trie::find(string s)
{
	bool chk = root->nFind(s);
	return chk;
}

int trie::count()
{
	int chk = root->nCount();
	return chk;
}