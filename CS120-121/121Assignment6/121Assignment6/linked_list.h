/*This is a linked list class that coordinates and fronts
for the actual linked list of nodes.  This class technically
only keeps track of two pointers, top and bottom, and the
nodes keep track of one another.  A combination of for loops
and recursions are used to accomplish the various functions.*/

class linked_list
{
private:
    /*top keeps track of the first item added to the
    queue, and bottom keeps track of the most recently
    added item.*/
    node*top, *bottom;
    int length;
public:
    linked_list();
    ~linked_list();
    eC append(entrytype);
    eC front(entrytype&);
    eC pop();
    int size();
    bool find(entrytype);
    void print();
    void reverseprint();
    eC insert(int, entrytype);
    eC remove(int);
    eC clear();
};

linked_list::linked_list()
{
    length = 0;
    top = new node();
    bottom = new node();
}

linked_list::~linked_list()
{
    ;
}

/*Both print functions use recursions called from
the nodes themselves.*/
void linked_list::print()
{
    bottom->print();
}

void linked_list::reverseprint()
{
    top->reverseprint();
}

/*Append sets up a double-linked list,
giving each node the address for the next
and the previous node.*/
eC linked_list::append(entrytype num)
{
    node* temp = new node;

    temp->info = num;
    temp->next = bottom;
    temp->prev = new node;
    bottom->prev = temp;

    /*This if statement sets up the first
    node added to the list as "top."  Since
    the new top will have an address in next,
    this will only occur if the list is empty.*/
    if (top->next == NULL)
    {
        top = temp;
    }

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
eC linked_list::front(entrytype& num)
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
the first item to the second item and
then erasing the original first item.*/
eC linked_list::pop()
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
        removes it from the list.*/
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

int linked_list::size()
{
    return length;
}

/*The find function is bare-bones due to the
reliance on the node function finder().*/
bool linked_list::find(entrytype num)
{
    bool x = 0;

    x = bottom->finder(num);

    return x;
}

/*This is the insert function.  Rather than recursions, this insert
uses for loops to locate the correct node position and make the insertion.
As was discussed during lecture, insert and remove anticipate the first
item of the list to be item 0 instead of item 1.

This is not the prettiest piece of code, but it gets the job done.
The placement of a node on the list is checked by using the length of the
list.  If the location is either at the top of the list, the bottom, or
beyond the list is each checked in an if else chain.  That determines 
how to attach the item so the list isn't disrupted.*/
eC linked_list::insert(int loc, entrytype dat)
{
    node* temp = new node;
    node* temp2 = new node; /*temp2 is used to preserve the current *top.*/

    temp->info = dat;

    temp2 = top;

    if (loc < length)
    {
        for (int i = 0; i < loc; i++)
        {
            temp2 = temp2->prev;
        }
        temp->prev = temp2;
        temp->next = temp2->next;
        temp->next->prev = temp; //It's awesome that this works.
        temp2->next = temp;
        if (loc == 0)
        {
            top = temp;
        }
        length++;
        return success;
    }
    else if (loc == length)
    {
        cout << "endtest" << endl;
        temp->next = bottom;
        temp->prev = new node;
        bottom->prev = temp;
        bottom = temp;
        length++;
        return success;
    }
    else if (loc > length)
    {
        /*This last if is essentially the same, but returns
        underflow instead of something else.*/
        cout << "overflowtest" << endl;
        temp->next = bottom;
        temp->prev = new node;
        bottom->prev = temp;
        bottom = temp;
        length++;
        return underflow;
    }
}

/*Remove functions very similarly to insert.  Rather than
the extra steps of inserting, it simply attaches up the
various prevs and nexts in order to omit the specied item.*/
eC linked_list::remove(int loc)
{
    node* temp = top;

    if (loc < length)
    {
        for (int i = 0; i < loc; i++)
        {
            temp = temp->prev;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        if (loc == 0)
        {
            top = temp->prev;
        }

        temp = new node;
        length--;
        return success;
    }
    else if (loc == length)
    {
        bottom->next->prev = bottom->prev;
        bottom = bottom->next;
        length--;
        return success;
    }
    else if (loc > length)
    {
        return underflow;
    }
}

eC linked_list::clear()
{   
    int co;
    co = top->clearer();
    if (co == 1)
    {
        cout << "All items deleted. Thoroughly." << endl;
    }
    else
    {
        cout << "Something went totally wrong." << endl;
    }
    top = new node;
    bottom = new node;
    length = 0;
    return success;
}