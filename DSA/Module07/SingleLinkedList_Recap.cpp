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

// void insert_tail(Node* &head, int val)
// {
//     Node* newNode = new Node(val);
//     Node* tmp = head;
//     while (tmp !=NULL)
//     {
//         tmp = tmp->next;
//     }
//     tmp->next = newNode;
// }

//insert by racking tail.TimeComplexity O(1)
void insert_tail2(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void print_linked_list(Node* head){
    Node* tmp = head;
    while (tmp !=NULL)
    {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }
    cout<<endl;
    
}

int size(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main()
{   
    Node* head = new Node(20);
    Node*  a = new Node(25);
    Node*  b = new Node(30);
    Node*  c = new Node(40);
    Node*  d = new Node(50);
    Node* tail = d;

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    cout<<"Tail : "<<tail->val<<endl;

    int pos, val;
    cin>>pos>>val;


    if(pos > size(head)){
        cout<<"Invaild Index"<<endl;
    }
    else if(pos == size(head)){
        insert_tail2(head,tail, val);
    }

    print_linked_list(head);
    cout<<"Tail : "<<tail->val<<endl;

    return 0;
}