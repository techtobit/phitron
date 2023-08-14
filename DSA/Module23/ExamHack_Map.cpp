#include<bits/stdc++.h>
using namespace std;

// problem 01 - 01-10min
// int main()
// {   
//     int n; cin>>n;
//     map<int, int>mp;
//     for(int i=0; i<n; i++)
//     {
//         int x; cin>>x;
//         mp[x]++;
//     }
//     for(auto it:mp)
//     {
//         if(it.second > 1)
//         {
//             cout<<"Duplicate Avaliable";
//             break;
//         }
//     }
//     return 0;
// }

int main()
{
    int t; cin>> t;
    set<int> st;
    while (t--)
    {
        int a, b;
        cin>> a>> b;
        if(a ==1)
        {
            st.insert(b);
        }
        else if(a==2)
        {
            st.erase(b);
        }
        else
        if(st.count(b)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    
    return 0;
}