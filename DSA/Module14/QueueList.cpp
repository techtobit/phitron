#include<bits/stdc++.h>
using namespace std;

class myQueue
{
    public:
    list<int>myList;
    void push(int val)
    {
        myList.push_back(val);
    }

    void pop()
    {
        myList.pop_front();
    }

    int front()
    {
        return myList.front();
    }

    int size()
    {
        return myList.size();
    }

    bool empty()
    {
        return myList.empty();
    }
}; 

int main()
{   
    myQueue st;
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