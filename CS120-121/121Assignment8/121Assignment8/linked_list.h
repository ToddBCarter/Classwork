class linked_list
{
private:
    node* top, * bottom;
    int length;
public:
    linked_list();
    ~linked_list();

    int size();

    eC append(entrytype);
    eC front(entrytype&);
    eC pop();

    void print();
    void reverseprint();
    eC insert(int, entrytype);
    eC remove(int);
    eC clear();

    bool linear_Search(entrytype);  //This function is most relevant to assignment 8.
    void insert_into_Sorted(int);  //And so is this one.  They both can be found towards the bottom.
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


void linked_list::print()
{
    bottom->print();
}

void linked_list::reverseprint()
{
    top->reverseprint();
}


eC linked_list::append(entrytype num)
{
    node* temp = new node;

    temp->info = num;
    temp->next = bottom;
    temp->prev = new node;
    bottom->prev = temp;

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

eC linked_list::pop()
{
    if (length > 0)
    {
        node* n;
        n = top;

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

eC linked_list::insert(int loc, entrytype dat)
{
    node* temp = new node;
    node* temp2 = new node;

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
        temp->next->prev = temp;  //I still love that this works.
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
        temp->next = bottom;
        temp->prev = new node;
        bottom->prev = temp;
        bottom = temp;
        length++;
        return success;
    }
    else if (loc > length)
    {
        temp->next = bottom;
        temp->prev = new node;
        bottom->prev = temp;
        bottom = temp;
        length++;
        return underflow;
    }
}

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
    co = top->cleaner();
    if (co != 1)
    {
        return fail;
    }
    top = new node;
    bottom = new node;
    length = 0;
    return success;
}

/*This is the same function as in the previous assignment,
as it still uses a linear search system.  In this case, the
linked list relies on the nodes using recursion to complete
the search.*/
bool linked_list::linear_Search(entrytype num)
{
    bool x = 0;

    x = bottom->finder(num);

    return x;
}

/*The insertion sort uses the other functions of the linked list
to find where a new value should go.  It then also uses a function
from the node class to insert a new node should the new value
go somewhere in the midst of the list.
Append() is used when a value is larger than the bottom.
Insert() is used when the value is smaller than the top.
The inserter() is used for all other cases.*/
void linked_list::insert_into_Sorted(int len)
{
    for (int i = 0; i < len; i++)
    {
        int number = rand() % 10000;

        node* temp = new node;
        temp->info = number;

        if (number >= bottom->info)
        {
            append(number);
        }
        else if (number <= top->info)
        {
            insert(0, number);
        }
        else
        {
            bottom->inserter(number);
        }
    }
}