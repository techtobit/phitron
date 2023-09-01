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

//insert at any positions
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

//insert node at head(in first positions)
void insert_at_node(Node* &head, int val)
{
    Node* newNode = new Node(val);
    Node* tmp = head;
    newNode->next = head;
    head = newNode;

}

void delete_from_position(Node* &head, int pos)
{
    Node* tmp = head;
    for (int i = 1; i < pos-1; i++)
    {
        tmp = tmp->next;
    }
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
    cout<<"Deleted From Position :"<<pos<<endl;
    
}

void delete_from_head(Node* &head)
{
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
    cout<<"Deleted Head"<<endl;
}

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
{   
    Node* head = NULL;
    while (true)
    {
        cout<<"Option 1: Insert at Tail"<<endl;
        cout<<"Option 2: Print Linked List"<<endl;
        cout<<"Option 3: Insert at Any Position"<<endl;
        cout<<"Option 4: Insert at Head"<<endl;
        cout<<"Option 5: Delete from position"<<endl;
        cout<<"Option 6: Delete Head"<<endl;
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
            if(pos == 0){
                insert_at_node(head, val);
            }
            else{
                insert_at_any_position(head, pos, val);
            }
        }
        else if(op == 4)
        {
            int val;
            cout<<"Enter Value : ";
            cin>>val;
            insert_at_node(head, val);
        }
        else if(op == 5)
        {
            int pos;
            cout<<"Enter Position : ";
            cin>>pos;
            if(pos==0){
                delete_from_head(head);
            }
            else{
                delete_from_position(head, pos);
            }
        }
        else if(op == 6)
        {
            delete_from_head(head);
        }
        
    }
    return 0;
}