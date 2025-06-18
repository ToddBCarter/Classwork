/*This is the tree class that main() primarily
interacts with.
TBSTree stands for Templated Binary Search Tree.*/

template<typename entrytype>
class tree {
private:
	node<entrytype>* root;
public:
	tree();


	/*-----------------------Assignment 14 functions------------------------------------*/
	void insert(entrytype); /*Function that calls node::sortedInsert().*/
	bool infixVisit(void(*visitor)(entrytype entry));  /*Applies a function to all nodes
													   specifically in infix order.*/
	bool find(entrytype);
};

template<typename entrytype>
tree<entrytype>::tree()
{
	root = new node<entrytype>; /*Nice, empty node.*/
}


/*Inserting new information into the tree.
It begins by creating a temporary node which will be passed to node::sortedInsert().
Then, it checks if root has been used or not.
Then assigns the entry to the temporary node, and passed it along.*/
template<typename entrytype>
void tree<entrytype>::insert(entrytype entry)
{
	node<entrytype>* information = new node<entrytype>;

	if (root->rootcheck == 0)  /*This checks if root has an entry or not.
							   If not, it gives it the entry and trips the rootcheck,
							   which prevents overwriting for future insertions.*/
	{
		root->info = entry;
		root->rootcheck = 1;
	}

	information->info = entry;

	root->sortedInsert(information);
}

template<typename entrytype>
bool tree<entrytype>::infixVisit(void(*visitor)(entrytype entry))
{
	bool chk = 0;
	chk = root->nInfixVisit(visitor);
	return chk;
}

template<typename entrytype>
bool tree<entrytype>::find(entrytype entry)
{
	bool chk = 0;
	chk = root->nFind(entry);
	return chk;
}