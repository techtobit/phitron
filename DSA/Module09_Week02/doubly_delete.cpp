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

void deleted_at_positons(Node* &head, int pos)
{
    Node* tmp = head;
    for(int i = 0; i<pos-1; i++ )
    {
        tmp = tmp->next;
    }
    cout<< tmp->val <<" ";
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

// void print_linked_list(Node *head)
// {
//     Node *tmp = head;
//     while (tmp != NULL)
//     {
//         cout << tmp->val << " ";
//         tmp = tmp->next;
//     }
//     cout << endl;
// }


// void print_reverse(Node* tail)
// {
//     Node* tmp = tail;
//     while(tmp !=NULL)
//     {
//         cout<< tmp->val << " ";
//         tmp = tmp->pre;
//     }

//     cout<< endl;
// }

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *tail = b;
    // Node* head = NULL;
    // Node* tail = NULL;

    // connection
    head->next = a;
    a->pre = head;
    a->next = b;
    b->pre = a;

    int pos;
    cin >> pos;

    if(pos >= size(head))
    {
        deleted_at_positons(head,pos);
    }
    // print_linked_list(head);
    // print_reverse(tail);

    cout << endl;
    return 0;
}