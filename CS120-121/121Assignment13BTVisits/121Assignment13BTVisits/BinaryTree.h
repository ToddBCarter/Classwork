/*This is the tree class that main() primarily
interacts with.  No extra effort was made to keep things
private from main().*/

class tree {
private:
	node* root;
public:
	tree();

	/*Assignment 11 function.*/
	void insert(string, string, string);/*Function that calls node::sortedInsert().*/

	/*Assignment 12 function.*/
	void infixPrint();  /*Prints all entries in infix order.*/

	/*Assignment 13 functions.  At the bottom of the page.*/
	void visit(void (*around)(record*)); /*Visits all nodes in the tree.*/
	void keyVisit(void (*around)(record*), string); /*Visits only the required key.*/
	void dataVisit(void (*around)(record*), string); /*Visits only the nodes with a specific substring.*/
};

tree::tree()
{
	root = new node; /*Nice, empty node.*/
}

/*Inserting new information is largely done by the nodes.*/
void tree::insert(string name, string spec, string data)
{
	root->sortedInsert(name, spec, data);
}

void tree::infixPrint()
{
	root->nInfixPrint();
}


/*The three visit functions serve mostly to pass the visitor
along down to the nodes which then have all the fun.*/
void tree::visit(void (*visitor)(record *r))
{	
	root->nVisit(visitor);
}

void tree::keyVisit(void (*visitor)(record* r), string n)
{
	root->nKeyVisit(visitor, n);
}

void tree::dataVisit(void (*visitor)(record* r), string n)
{
	root->nDataVisit(visitor, n);
}