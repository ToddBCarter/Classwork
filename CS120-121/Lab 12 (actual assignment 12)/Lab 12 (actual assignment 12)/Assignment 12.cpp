/*Todd Carter
Section 3
Assignment 12
11-15-2021*/

/*This is a double linked list as taken from the completed Lab 12,
though the double linking is not used for the additions requested by
the assignment.  The third chosen variable was age as an integer.*/

#include<iostream>
#include<string>
using namespace std;

class node {
private:
    node* next;
    node* rev;
    int id, age, len;
    string name;
public:
    void setnext(node* n) { next = n; }
    void setdata(string n, int i, int j) { name = n, id = i, age = j; }
    void getrev(node* n) { rev = n; }
    void print();
    void reverseprint();
    void append(node*);
    void length();
    void clear();
};

void node::print() {
    cout << name << endl;
    cout << id << "\n" << age << endl;
    if (next != NULL)
        next->print();
}

void node::reverseprint()
{
    cout << name << endl;
    if (rev != NULL)
        rev->reverseprint();
}

void node::append(node *n)
{
    if (next == NULL)
        setnext(n);
    else
        next->append(n);
}

void node::length()
{
    len = len + 1;
    if (next != NULL)
    {
        next->len = len;
        next->length();
    }
    else
    {
        cout << "Length oughta be about: " << len << endl;
    }
}

void node::clear()
{
    if (next != NULL)
    {
        next->clear();
    }
    delete this;
}

int main() {
    node* head, * temp, * first, * appNode;
    int legion;
    int length;

    temp = new node();
    temp->setdata("Sally" , 1 , 34);  //Sally has Fred's address, first has her address.
    temp->setnext(NULL);
    first = temp;  //First is given Sally's address.
    first->getrev(temp);  //First's rev is set to Sally as well
    head = temp;

    temp = new node();
    temp->setdata("Fred", 2, 25);
    temp->setnext(head);
    head->getrev(temp);  //Sally's rev is set to Fred's address here
    head = temp;  //Goodbye Sally, hello Fred.

    temp = new node();
    temp->setdata("Anne", 3, 27);
    temp->setnext(head);
    head->getrev(temp);
    head = temp;

    temp = new node();
    temp->setdata("Alan", 4, 31);
    temp->setnext(head);
    head->getrev(temp);
    head = temp;

    cout << "How many Bobs do you want?\n";
    cout << "'We are legion, we are Bob.'\n";
    cin >> legion;
    for (int i = 0; i < legion; i++)
    {
        temp = new node();
        temp->setdata("Bob", i, 38);
        temp->setnext(head);
        head->getrev(temp);
        head = temp;
    }

    appNode = new node();
    appNode->setdata("Jimmy", 99, 38);
    head->append(appNode);  //Jimmy 99 shows up "before" Sally.

    //head->clear();  //If clear is called, it all breaks as intended, so this is commented out.
    head->length();
    head->print();
    //first->reverseprint();  //Used for the lab, not needed for the assignment.


}

