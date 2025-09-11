/*The queue class relies on two pointer variables, top and bottom,
to keep track of the first and last items of the queue.  Bottom is 
used to append new items, while top is used to pop items from the
list.*/

class queue
{
private:
    /*top keeps track of the first item added to the
    queue, and bottom keeps track of the most recently
    added item.*/
	node* top, *bottom;
	int length;
public:
	queue();
	~queue();
	eC append(entrytype);
	eC front(entrytype&);
	eC pop();
	int size();
	bool find(entrytype);
    void print();
};

queue::queue()
{
	length = 0;
	top = new node();
	bottom = new node();
}

queue::~queue()
{
    ;
}

void queue::print()
{
    bottom->print();
}

/*Append sets up a double-linked list,
giving each node the address for the next
and the previous node.  This is useful
for popping the top off later.

First, a temporary node is set up.  This
node is given the information, and then
is given the address to the previous "last" item
in the list, called "bottom."  Then that "last" 
item is given the address of the new temp node, 
setting up the double-link.  Then the "last" 
item is reassigned to the temp node, which adds 
the temp node to the queue.*/
eC queue::append(entrytype num)
{
    node *temp = new node;

    temp->info = num;
    temp->next = bottom;
    bottom->prev = temp;

    /*This if statement sets up the first
    node added to the list as "top."  Since
    the new top will have an address in next,
    this will only occur if the list is empty.*/
    if (top->next == NULL)
    {
        top = temp;
    }

    /*This is the error code.  Basically, if
    it failes to add the temp node to the queue
    by reassigning bottom, it will error out.*/
    if (!(bottom = temp))
    {
        return overflow;
    }

    length++;

    return success;
}

/*Since both top and bottom are actively
monitored, it's easiest to simply take
the public info from the current top.*/
eC queue::front(entrytype& num)
{
    if (length > 0)
    {
        num = top->info;
        return success;
    }
    else
    {
        return underflow;
    }
}

/*This pop() uses the double-linked list
in order to keep track of the first item
added to the list.  This allows for the
relatively easy adjustment of changing
that first item to the second item and
then erasing the original first item.*/
eC queue::pop()
{
    if (length > 0)
    {
        node* n;
        n = top;

        /*The top and bottom both need to
        have addresses in next. This means 
        turning top->next into NULL 
        effectively removes that node from 
        the list, and then changing top 
        removes it from the queue.*/
        top->next = NULL;
        top = top->prev;

        n = new node;

        length--;
        return success;
    }
    else
    {
        return underflow;
    }
}

/*The path of least resistance.*/
int queue::size()
{
    return length;
}

/*The find function is bare-bones due to the 
reliance on the node function finder().*/
bool queue::find(entrytype num)
{   
    bool x = 0;

    x = bottom->finder(num);
    
    return x;
}