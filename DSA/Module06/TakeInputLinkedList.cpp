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

//insert add last positon
void insert_at_tail(Node* &head, int v)
{
    Node * newNode = new Node(v);
    Node * tmp = head;
    if(head ==NULL)
    {
        head = newNode;
        cout<<endl
        <<"Instert at Head"<<endl; 
        return;
    }

    while (tmp->next !=NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    
};

void print_linked_list(Node* head)
{
    cout<<"Your Linked List : ";
    Node * tmp = head;
    while (tmp !=NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
    
}

int main()
{   int val;
    Node* head = NULL;
    while (true)
    {
        cin>>val;
        if(val == -1) break;
        insert_at_tail(head, val);
    }
    print_linked_list(head);
}