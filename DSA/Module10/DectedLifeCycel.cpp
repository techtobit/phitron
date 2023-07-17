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



int main()
{   
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);

    // connection 
    head->next = a;
    a->next =b;
    b->next = c;
    // any of htem in cycle 
    // c->next = c;
    // c->next = head;
    // c->next = b
    
    // not cycle 
    c->next =NULL;

    Node* slow = head;
    Node* fast = head;
    bool flag = false;
    while (fast != NULL && fast->next !=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
        {
            flag = true;
            break;
        }
    }
    
    if(flag == true) cout<< "Cycle Found" << endl;
    else cout<< "Cycle Not Found" << endl;
    return 0;
}