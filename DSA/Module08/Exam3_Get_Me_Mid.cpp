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


void short_linkedList(Node* head)
{
    Node * tmp = head;
    for(Node* i = tmp; i->next !=NULL; i= i->next)
    {
        for(Node* j = i->next; j!=NULL; j= j->next)
        {
            if(i->val < j->val)
            {
                swap(i->val, j->val);
            }
        }
    }
}

int count_sizee(Node* head)
{   
    Node* tmp = head;
    int count = 0;
    while (tmp !=NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

void get_mid(Node* head)
{
    int size = count_sizee(head);
    int mid = (size+1)/2;
    Node* tmp = head;
    for(int i=0; i<mid-1; i++)
    {
        tmp = tmp->next;
    }
    if(size % 2 == 0)cout<<tmp->val<<" "<<tmp->next->val<<endl;
    else cout<<tmp->val<<endl;
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
    short_linkedList(head);
    int size = count_sizee(head);
    get_mid(head);
    return 0; 

}
