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

void insert_at_tail(Node* &head, int v)
{
    Node * newNode = new Node(v);
    Node * tmp = head;
    if(head ==NULL)
    {
        head = newNode;
        cout<<endl
        <<"Instert at Head"<<endl
        <<endl;
        return;
    }

    while (tmp->next !=NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    cout<<endl<<endl;
    
};

void insert_at_any_position(Node* &head, int pos, int val)
{
    Node* newNode = new Node(val);
    Node* tmp = head;
    for(int i=1; i<pos-1; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    cout<<endl<<endl<<"Inserted at pos : "<<pos<<endl;
}

void print_linked_list(Node * head)
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
{   
    Node* head = NULL;
    while (true)
    {
        cout<<"Option 1: Insert at Tail"<<endl;
        cout<<"Option 2: Print Linked List"<<endl;
        cout<<"Option 3: Insert at Any Position"<<endl;
        cout<<"Option 4: Terminate"<<endl;
        int op;
        cin>>op;
        if(op == 1){
            cout<<"Please Enter Value : " ;
            int v;
            cin>>v;
            insert_at_tail(head, v);
        }
        else if(op == 2){
            print_linked_list(head);
        }
        else if(op == 3){
            int pos;
            cout<<"Insert Position : ";
            cin>>pos;
            int val;
            cout<<"Insert Vale : "<<endl;
            cin>>val;
            insert_at_any_position(head, pos, val);
        }
        else if(op == 4)
        {
            break;
        }
        
    }
    return 0;
}