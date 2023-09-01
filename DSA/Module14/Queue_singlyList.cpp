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

class myQueue
{
    public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;
    void push(int val)
    {
        sz++;
        Node* newNode  = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
    }

    void pop()
    {
        sz--;
        Node* deleteNode =head;
        head =  head->next;
        delete deleteNode;
        if(head == NULL)
        {
            tail = NULL;
        }
    }

    int front()
    {
        return head->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        if(sz == 0) return true;
        else return false;
    }
}; 

int main()
{   
    myQueue st;
    // s.push(20);
    // s.push(15);
    // s.push(10);
    // cout<<s.front() << endl;
    // s.pop();
    // cout<<s.front() << endl;
        // for n myListalue 
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        st.push(x);
    }

    while (!st.empty())
    {
        cout<<st.front() <<endl;
        st.pop();
    }
    return 0;
}