#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    string val;
    Node* next;
    Node* pre;

    Node(string val)
    {
        this->val = val;
        this->next = NULL;
        this->pre = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, string val)
{
    Node* newNode = new Node(val);
    if(tail == NULL || head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->pre = tail;
    tail = newNode;
}


void navigiate_links(Node* head, Node* &curNode,string commandLists)
{
    if(commandLists == "visit")
    {
        string addressVisit;
        cin.ignore(); 
        getline(cin, addressVisit);
        Node* tmp = head;
        while (tmp !=NULL)
        {
            if(tmp->val == addressVisit)
            {
                cout<<tmp->val<< endl;
                curNode = tmp;
                return;
            }
            tmp = tmp->next;
        }
        cout<< "Not Available" << endl;
        
    }
    else if(commandLists == "next")
    {
        if(curNode  !=NULL && curNode->next !=NULL)
        {
            curNode = curNode->next;
            cout<< head->val << endl;
        }
        else cout<< "Not Available" << endl;
        
    }
    else if(commandLists == "prev")
    {
        if(curNode !=NULL && curNode->pre !=NULL)
        {
            curNode = curNode->pre;
            cout<< curNode->val << endl;
        }
        else cout<< "Not Available" << endl;
    }
}


int main()
{   
    Node* head = NULL;
    Node* tail = NULL;
    
    string addressName;
    while (true)
    {
        cin>> addressName;
        if(addressName == "end") break;
        insert_at_tail(head, tail, addressName);
    }


    int cl;
    cin >> cl;
    cin.ignore(); 
    Node* curNode = head;
    for (int i = 1; i <= cl; i++)
    {
        string commandLists;
        cin>>commandLists;
        navigiate_links(head,curNode, commandLists);
    }

    return 0;
}