/*Honestly, not much happens here.  All the heavy lifting is
done by the node class over in node.h.  These basically just
redirect variables from main to the nodes, kind of like
traffic guards.*/

#include"node.h"  //Putting the include here prevents some node tampering.

class tree
{
private:
	node* root;

public:
	tree();

	eC grow(int);  //The commander of node grow().
	double evaluate();  //Commander for node evaluate.
	eC erase();  //The commander of node clear().
	eC print();
};

tree::tree()
{
	root = NULL;
}

eC tree::grow(int size)
{
	root = new node;
	root->grow(size, 0);  //Two arguments.  Explained in node.h.
	return success;
}

double tree::evaluate()
{
	double total = 0;

	if (root != NULL)
	{
		total = root->evaluate();
	}
	else
	{
		return fail;
	}

	return total;
}

eC tree::erase()
{
	root->clear();
	root = NULL;  //Sets root to NULL so as to allocate new space.
	return success;
}

eC tree::print()
{
	if (root != NULL)
	{
		root->print();
		return success;
	}
}