#include <iostream>
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

void insert_head(Node* &head, Node* &tail, int val)
{
    Node* newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->pre = newNode;
    head = newNode;
}

void insert_at_postion(Node* head, int pos, int val)
{
    Node* newNode = new Node(val);
    Node* tmp = head;
    for (int i = 1; i < pos-1; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    tmp->next->pre = newNode;
    newNode->pre = tmp;
}

int size(Node* head)
{
    Node* tmp = head;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

void print_node(Node* head)
{   
    cout<<"L -> ";
    Node* tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_node_reverse(Node* tail)
{
    cout<<"R -> ";
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
    Node* head = NULL;
    Node* tail = NULL;

    int qur;
    cin >> qur;

    for (int i = 1; i <= qur; i++)
    {
        int pos, val;
        cin >> pos >> val;
        if (pos > size(head))
        {
            cout << "Invalid"<<endl;
        }
        else if (pos == 0)
        {
            insert_head(head, tail, val);
        }
        else
        {
            insert_at_postion(head, pos, val);
        }
        
        if(head)
        {
            print_node(head);
            print_node_reverse(tail);
        }
    }
    // print_node(head);
    // print_node_reverse(tail);
    return 0;
}
