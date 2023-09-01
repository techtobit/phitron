#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node* next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};


int main()
{   
    // Node* head = new Node(10);
    // Node* a = new Node(15);
    // Node* b = new Node(20);
    // Node* c = new Node(25);
    // Node* d = new Node(30);

    Node* node = new Node(5);
    cout << node->val << endl;

    // head->next = a;
    // a->next = b;
    // b->next = c;
    // c->next =d;

    // Node* temp = head;

    // while (temp !=NULL)
    // {
    //     cout<<temp->val<<endl;
    //     temp = temp->next;
    // }
    
    return 0;
}