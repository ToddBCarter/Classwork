/*Todd Carter
Section 3
Assignment 13
11-30-2021*/

/*The modifications mostly use while loops
in order to search through the linked list.*/

class node {
private:
    node* next;
    string name;
public:
    void setnext(node* n) { next = n; } 
    void setdata(string n) { name = n; }  
    void print(); 
    void clear();
    void append(node*);
    int find(string);
    string getname() { return name; }
    node* getnext() { return next; }
};

void node::clear() {
    if (next != NULL)
        next->clear();
    delete this;
}

void node::print() {
    cout << name << endl;
    if (next != NULL)
        next->print();
}

void node::append(node* n)
{
    if (next == NULL)
        setnext(n);
    else
        next->append(n);
}

int node::find(string q)
{
    int found = 0;
    if (next != NULL) {
        if (name.compare(q) == 0) {
            found = 1;
        }
        else
        {
            found = next->find(q);
        }
    }
    return found;
}

// Definition of the linked list class

class linkedlist {
private:
    node* head;
    int len;
public:
    linkedlist();
    void push(node*);
    void print();
    void clear();
    int count();
    void append(node*);
    int find(string);
    string get(int);
};

linkedlist::linkedlist() { // constructor
    head = NULL;
    len = 0;
}

void linkedlist::push(node* n) {
    n->setnext(head);
    head = n;
    len = len + 1;
}

void linkedlist::print() {
    if (head != NULL) {
        head->print();
    }
}

void linkedlist::clear() {
    if (head != NULL) {
        head->clear();
    }
    head = NULL;
    len = 0;
}

int linkedlist::count() {
    return len;
}

void linkedlist::append(node* p)
{
    if (head != NULL) {
        head->append(p);
        len = len + 1;
    }
}

/*The pointer variable p is used so as to 
preserve head.*/
int linkedlist::find(string q)
{
    int found = 0;
    string name;
    node* p;
    
    p = head;

    while (p != NULL)
    {
        name = p->getname();
        if (name.compare(q) == 0) 
        {
            found = 1;
        }
        p = p->getnext();
    }

    return found;
}

string linkedlist::get(int n)
{
    string name = "";
    node* p;

    p = head;

    int nth = 1;
    while (p != NULL) {
        if (nth == n)
        {
            name = p->getname();
        }
        nth++;
        p = p->getnext();
    }

    return name;
}