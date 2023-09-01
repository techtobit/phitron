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


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while (true)
    {
        cin>>val;
        if(val == -1)break;
        insert_tail2(head, tail, val);
    }

    for(Node* i = head; i->next !=NULL; i = i->next){
        for(Node* j =i->next; j!=NULL; j=j->next)
        {
            if(i->val > j->val)
            {
                swap(i->val, j->val);
            }
        }
    }

    print_linked_list(head);
    return 0; 

}
