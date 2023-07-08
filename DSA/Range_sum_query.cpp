#include<bits/stdc++.h>
using namespace std;

int main()
{   int n, q; 
    cin>>n>>q;
    // vector<int> a(n);
    int a[n];
    for (size_t i = 0; i < n; i++)
    {
        cin>>a[i];
    };
    
    // for (size_t i = 0; i < n; i++)
    // {
    //     cout<<a[i]<< " ";
    // }
    
    while (q--)
    {
        int l, r;
        cin>>l>>r;
        l--;
        int sum = 0;
        for (size_t i = l; i < r; i++)
        {
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
    
    

    return 0;
}