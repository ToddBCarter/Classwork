/*Todd Carter
Section 3
Lab 12
11-13-2021*/

/*This is a double linked list that uses pointer
rev to travel backwards and pointer next to travel 
forwards along the list.*/

#include<iostream>
#include<string>
using namespace std;

class node {
private:
    node* next;
    node* rev;
    string name;
public:
    void setnext(node* n) {next = n;}
    void setdata(string n) {name = n;}
    void getrev(node* n) { rev = n; }
    void print();
    void reverseprint();
};

void node::print() {
    cout << name << endl;
    if (next != NULL)
        next->print();
}

void node::reverseprint()
{
    cout << name << endl;
    if (rev != NULL) 
        rev->reverseprint();
}

int main() {
    node* head, * temp, *first;
    int legion;

    temp = new node(); 
    temp->setdata("Sally");
    temp->setnext(NULL);
    first = temp;
    first->getrev(temp);
    head = temp;   

    temp = new node();  
    temp->setdata("Fred"); 
    temp->setnext(head);
    head->getrev(temp);
    head = temp;   

    temp = new node();
    temp->setdata("Anne");
    temp->setnext(head);
    head->getrev(temp);
    head = temp;  

    temp = new node();    
    temp->setdata("Alan");
    temp->setnext(head);
    head->getrev(temp);
    head = temp;

    cout << "How many Bobs do you want?\n";
    cout << "'We are legion, we are Bob.'\n";
    cin >> legion;
    for (int i = 0; i < legion; i++)
    {
        temp = new node();
        temp->setdata("Bob");
        temp->setnext(head);
        head->getrev(temp);
        head = temp;
    }

    head->print();
    first->reverseprint();
}

