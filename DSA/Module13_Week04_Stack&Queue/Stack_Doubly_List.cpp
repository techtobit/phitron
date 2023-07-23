#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


class myStack
{
public :
    Node* head = NULL;
    Node* tail = NULL;

    //for geting size track the size during push;
    int sz=0;
    void push(int val)
    {
        sz++;
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = tail->next;
        
    }
    
    void pop()
    {
        sz--;
        Node* deleteTail = tail;
        tail = tail->prev;
        if(tail == NULL)
        {
            head = NULL;
        }
        else 
        {
            tail->next = NULL;
        }
        delete deleteTail;
    }

    int top()
    {
        return tail->val;
    }

    int size()
    {
        return sz;
    }

    int empty()
    {
        if(sz == 0) return true;
        else return false;
    }
}; 

int main()
{   
    myStack st;
    // st.push(10);
    // st.push(20);
    // cout<< st.top()<<endl; //20
    // st.pop(); //remove from top. 20
    // cout<< st.top() <<endl;

    // for n value 
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
        cout<<st.top() <<endl;
        st.pop();
    }
    
    return 0;
}