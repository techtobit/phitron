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

void print_reverse(Node* head)
{
    Node* tmp = head;
    while(tmp !=NULL)
    {
        cout<< tmp->val << " ";
        tmp = tmp->pre;
    }

    cout<< endl;
}



int main()
{   
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* tail = b;
    // Node* c = new Node(40);

    // connection 
    head->next = a;
    a->pre = head;
    a->next =b;
    b->pre = a;

    print_node(head);
    print_reverse(tail);
    cout<<endl;
    return 0;
}