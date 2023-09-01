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

void insert_at_tail(Node* &head, Node* &tail, int val)
{
    Node* newNode = new Node(val);
    Node* tmp = head;
    if(tmp == NULL || tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;

}

void remove_duplicates(Node* &head)
{
    Node* tmp = head;
    while(tmp !=NULL)
    {
        while (tmp->next !=NULL && tmp->val == tmp->next->val)
        {
            tmp->next = tmp->next->next;
        }
        tmp = tmp->next;
        
    }
}



void print_node(Node* head)
{
    Node* tmp = head;
    while (tmp !=NULL)
    {
        cout<< tmp->val << " ";
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
        if(val == -1) break;
        insert_at_tail(head, tail, val);
    }
    
    for(Node* i = head; i !=NULL; i=i->next)
    {
        for(Node* j = i->next; j !=NULL; j=j->next)
        {
            if(i->val >= j->val)
            {
                swap(i->val, j->val);
            }
        }
    }

    // remove_duplicates(head);
    print_node(head);
    return 0;
}