#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *pre;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->pre = NULL;
    }
};

void insert_head(Node *&head, Node* &tail, int val)
{
    Node *newNode = new Node(val);
    if (newNode == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->pre = newNode;
    head = newNode;
}


void insert_at_tail(Node* &head, Node* &tail, int val)
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

int size(Node* head)
{
    Node* tmp = head;
    int count = 0;
    while (tmp !=NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
    cout<<endl;
};

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_reverse(Node* tail)
{
    Node* tmp = tail;
    while(tmp !=NULL)
    {
        cout<< tmp->val << " ";
        tmp = tmp->pre;
    }

    cout<< endl;
}

int main()
{
    // Node *head = new Node(10);
    // Node *a = new Node(20);
    // Node *b = new Node(30);
    // Node *tail = b;
    Node* head = NULL;
    Node* tail = NULL;

    // connection
    // head->next = a;
    // a->pre = head;
    // a->next = b;
    // b->pre = a;

    int pos, val;
    cin >> pos >> val;

    if (pos == 0)
    {
        insert_head(head,tail,val);
    }
    else if(pos == size(head))
    {
        insert_at_tail(head, tail, val);
    }
    print_linked_list(head);
    print_reverse(tail);

    cout << endl;
    return 0;
}