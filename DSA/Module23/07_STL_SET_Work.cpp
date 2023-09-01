#include<bits/stdc++.h>
using namespace std;

int main()
{   
    set<int> st;
    int n; cin>>n;
    while(n--)
    {
        int val; cin>>val;
        st.insert(val);
    }
    for(auto it=st.begin(); it!=st.end(); it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}