#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;
    Node* pre;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->pre = NULL;
    }
};


//reverse Dubly Method 2 -
void print_reverse(Node* &head, Node* &tail)
{
    Node *i = head;
    Node *j = tail;
    while (i !=j && i->next !=j)
    {
        swap(i->val, j->val);
        i = i->next;
        j = j->pre;
    }
    
    
}


void print_node(Node* head)
{
    Node* tmp = head;
    while(tmp !=NULL)
    {
        cout<< tmp->val << " ";
        tmp = tmp->next;
    }

    cout<< endl;
}


int main()
{   
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* tail = c;

    // connection 
    head->next = a;
    a->pre = head;
    a->next =b;
    b->pre = a;
    b->next = c;
    c->pre =b;

    print_reverse(head,tail);
    print_node(head);
    cout<<endl;
    return 0;
}