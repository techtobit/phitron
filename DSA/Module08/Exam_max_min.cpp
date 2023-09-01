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
    Node* tmp  = head;
    int max = INT_MIN;
    int min = INT_MAX;
    while (tmp->next !=NULL)
    {
        if(min > tmp->val)
        {
            min = tmp->val;
        }
        if(max < tmp->val)
        {
            max = tmp->val;
        }

        head = tmp->next;
    }
    cout<<max<<" "<<min<<endl;
    
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
    print_linked_list(head);
    return 0; 

}
