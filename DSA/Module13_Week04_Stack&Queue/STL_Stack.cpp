#include<bits/stdc++.h>
using namespace std;

int main()
{   
    stack<int>myStack;
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
        myStack.push(x);
    }

    while (!myStack.empty())
    {
        cout<<myStack.top() <<endl;
        myStack.pop();
    }
    
    return 0;
}