#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n; cin>> n;
    for(int i=1; i<=n; i++)
    {
        cout<<i;
    }
    cout<<endl;

    for(int i=2; i<=n; i++)
    {
        cout<<i<<" ";
        for(int j=2; j<=n-1; j++)
        {
            cout<<" ";
        }
        for (int i = n; i <=n; i++)
        {
            cout<<i;
        }
        cout<<endl;
    }
    for(int i=1; i<=n; i++)
    {
        for (int i = n; i <=n; i++)
        {
            cout<<i;
        }
        
    }
    cout<<endl;
    return 0;
}