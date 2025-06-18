/*Todd Carter
Section 3
Lab 13
12-1-2021*/

class node {
private:
    node* next;
    string name;
public:
    void setnext(node* n) { next = n; }
    void setdata(string n) { name = n; }
    void print();
    void clear();
    void reverseprint();
    node * getdata() { return next; }
    string getname() { return name; }
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

void node::reverseprint()
{
    if (next != NULL)
    {
        next->reverseprint();
    }
    cout << name << endl;
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
    void reverseprint();
    string pop();
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

void linkedlist::reverseprint()
{
    if (head != NULL) {
        head->reverseprint();
    }
}

string linkedlist::pop()
{
    node* p;
    string data = "";
    if (head != NULL)
    {
        p = head;
        data = head->getname();
        head = head->getdata();
        delete p;
        len = len - 1;
    }    
    return data;
}