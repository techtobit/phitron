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


void insert_head(Node* &head, int v)
{
    Node* newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}

void insert_tail(Node* &head, Node* &tail, int v)
{
    Node* newNode = new Node(v);
    if(head == NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    tail = tail->next;
    tail = newNode;
}


// void insert_tail(Node* &head, Node* &tail, int v)
// {
//     Node* newNode = new Node(v);
//     if (head == NULL)
//     {
//         head = newNode;
//         tail = newNode;
//         return;
//     }
//     tail->next = newNode;
//     tail = newNode;
// }

// void print_linked_list(Node* head, Node* tail)
// {
//     cout<<head->val<<" "<<tail->val<<endl;
    
// }

void print_linked_list(Node* &head, Node* &tail)
{
    if(head == NULL || tail == NULL)
    {
        tail = head;
        head = tail;
    }
    cout<<head->val<<" "<<tail->val<<endl;
    
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int qr;
    cin>>qr;
    for(int i=0; i<qr; i++)
    {
        int x;
        cin>>x;
        if(x == 0)
        {
            int v;
            cin>>v;
            insert_head(head,v);
        }
        else if(x == 1){
            int v;
            cin>>v;
            insert_tail(head,tail,v);
        }
        else cout<< "Invalid Index"<<endl;
        print_linked_list(head, tail);
    }
    

}
