#include<bits/stdc++.h>
using namespace std;

class myStack
{
public :
    list<int> myList;
    void push(int val)
    {
        myList.push_back(val);
    }
    
    void pop()
    {
        myList.pop_back();
    }

    int top()
    {
        return myList.back();
    }

    int size()
    {
        return myList.size();
    }

    int empty()
    {
        if(myList.size() == 0) return true;
        else return false;
    }
}; 

int main()
{   
    myStack st;
    st.push(10);
    st.push(20);
    // cout<< st.top()<<endl; //20
    // st.pop(); //remomyListe from top. 20
    // cout<< st.top() <<endl;

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
        cout<<st.top() <<endl;
        st.pop();
    }
    
    return 0;
}