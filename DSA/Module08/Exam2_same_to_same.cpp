#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void insert_tail2(Node *&head2, Node *&tail2, int val2)
{
    Node *newNode = new Node(val2);
    if (head2 == NULL)
    {
        head2 = newNode;
        tail2 = newNode;
        return;
    }
    tail2->next = newNode;
    tail2 = newNode;
}

void print_linked_list(Node *head, Node *head2)
{
    Node *tmp = head;
    Node *tmp2 = head2;
    bool flag = true;
    int size = 0;
    int size2 = 0;
    while (tmp !=NULL)
    {
        size++;
        tmp = tmp->next;
    }

    while (tmp2 !=NULL)
    {
        size2++;
        tmp2 = tmp2->next;
    }

    if(size != size2){
        flag = false;
    }
    
    while (tmp != NULL && tmp2 != NULL)
    {
        if (tmp->val != tmp2->val)
        {
            flag = false;
            break;
        }

        tmp2 = tmp2->next;
        tmp = tmp->next;
    }

    while (tmp ==NULL &&  tmp2 ==NULL )
    {
        flag = true;
        break;
    }
    

    if(flag == true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_tail(head, tail, val);
    }

    Node *head2 = NULL;
    Node *tail2 = NULL;

    int val2;
    while (true)
    {
        cin >> val2;
        if (val2 == -1)
            break;
        insert_tail2(head2, tail2, val2);
    }
    print_linked_list(head, head2);
    return 0;
}
