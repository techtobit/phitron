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


//insert at head
void insert_head(Node* &head, Node* &tail, int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->pre = newNode;
    head = newNode;
}


//deleted node for head;
void delete_from_head(Node* &head)
{
    if(head == NULL)
    {
        cout<<"Invalid Index"<<endl;
        return;
    }
    Node* deleteNode = head;
    head = head->next;
    head->next->pre  = NULL;
    delete deleteNode;
}


//Insert New Node at Tail;
int insert_at_tail(Node* &tail, int val)
{
    Node* newNode = new Node(val);
    tail->next = newNode;
    newNode->pre = tail;
    tail= newNode;
}

int size(Node* head){
    Node* tmp = head;
    int count = 0;
    while (tmp !=NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
    
}


void print_linkedList(Node* head)
{
    Node* tmp = head;
    while (tmp != NULL)
    {
        cout<< tmp->val << " ";
        tmp = tmp->next;
    }
    cout<<endl;
    
}

int main()
{   
    // Node* head = NULL;
    // Node* tail = NULL;
    Node* head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *tail = b;

    // connection
    head->next = a;
    a->pre = head;
    a->next = b;
    b->pre= a;

    int val;
    cin>>val;

    // insert_head(head, tail, val);
    // delete_from_head(head);
    // insert_at_tail(tail, val);
    print_linkedList(head);

    return 0;
}