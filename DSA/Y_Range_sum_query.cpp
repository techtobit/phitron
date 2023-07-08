#include<bits/stdc++.h>
using namespace std;

int main()
{   long long n, q; 
    cin>>n>>q;
    int a[n];
    for (size_t i = 0; i < n; i++)
    {
        cin>>a[i];
    };
    
    long long pre[n];
    pre[0]=a[0];
    for (size_t i =1 ; i < n; i++)
    {
        pre[i]=a[i]+pre[i-1];
    }
    
    while (q--)
    {
        long long l, r;
        cin>>l>>r;
        l--;
        r--;
        long long sum;
        if(l==0) sum=pre[r];
        else sum=pre[r]-pre[l-1];
        cout<<sum<<endl;
    }
    
    

    return 0;
}