class node
{
private:
public:
	node* L, * R;  //Pointers for the left and right subnodes.
	int data;  //Node value.
	string op;  //Node operator.

	node();  //Constructor.
	void grow(int,int);  //Node grow.  Uses two args.
	void clear();  //Node clear.
	void print();  //Node print.
	double evaluate();  //Node evaluate.
};

node::node()
{
	L = NULL;
	R = NULL;

	data = rand() % 10 + 1;  //Setting the node to a random value.

	int temp = rand() % 7;  //Setting the node to a random operator.
	if (temp == 0)
	{
		op = "+";
	}
	else if (temp == 1)
	{
		op = "-";
	}
	else if (temp == 2)
	{
		op = "*";
	}
	else if (temp == 3)
	{
		op = "/";
	}
	else if (temp == 4)
	{
		op = "^";
	}
	else if (temp == 5)
	{
		op = "sin";
	}
	else if (temp == 6)
	{
		op = "cos";
	}
}

/*The grow recursion uses two arguments in order
to allow for the main user to change the depth of
the tree.  d is always 0 as it is the starting
location, but as it needs to increment for each step
of the recursion, it can't be set within the node.
The zeroth location is instead handed over by the
tree function during the call.*/
void node::grow(int depth, int d)
{
	int temp = rand() % 100;
	if (temp <= 10 || d >= depth)
	{
		return;
	}
	
	L = new node;
	L->grow(depth, (d + 1));
	R = new node;
	R->grow(depth, (d + 1));
	
}

/*The clear function recursively travels down the list
and deletes all nodes as the recursion collapses.*/
void node::clear()
{
	if (L != NULL)
	{
		L->clear();
	}
	if (R != NULL)
	{
		R->clear();
	}
	
	delete this;
}

/*Recursive print function.  
Minimally pretty.  More or less functional.*/
void node::print()
{
	if (L == NULL && R == NULL)
	{
		cout << " " << data << " ";
	}
	else if (op == "sin" || op == "cos")  //Just ignore R for sin and cos.
	{
		cout << op;
		cout << " (";
		L->print();
		cout << ")";
	}
	else
	{
		cout << "(";
		L->print();
		cout << ") ";
		cout << op;
		cout << " (";
		R->print();
		cout << ")";
	}
}

/*Recursive evaluate function.  Relies heavily on cmath
to perform the various operations.

Note that values are expected in radians and not degrees.*/
double node::evaluate()
{
	if (L == NULL && R == NULL)  //First, check to see if it's a leaf node.
	{
		return data;  //Return the data of the leaf node up to node that will perform the operations.
	}

	double total = 0;

	/*Recursively move down the tree, performing the same
	checks and operations where possible.  Each returned value
	is used in the required operations before the resulting total
	is returned upward.*/

	double lValue = L->evaluate();
	double rValue = R->evaluate();

	//Perform the operations by way of this if/else.
	if (op == "+")
	{
		total = lValue + rValue;
	}
	else if (op == "-")
	{
		total = lValue - rValue;
	}
	else if (op == "*")
	{
		total = lValue * rValue;
	}
	else if (op == "/")
	{
		total = lValue / rValue;
	}
	else if (op == "^")
	{
		total = pow(lValue, rValue);
	}
	else if (op == "sin")  //Just ignore rValue for cos and sin.
	{
		total = sin(lValue);
	}
	else if (op == "cos")  //Don't have to reset it, even, just not using it.
	{
		total = cos(lValue);
	}

	return total; //The value that is returned upwards.
}