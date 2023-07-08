#include<bits/stdc++.h>
using namespace std;

int main()
{   long long n; 
    cin>>n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    vector<long long> pre(n);
    pre[0] = a[0];
    for (int i = 1; i <n; i++)
    {
        pre[i] = a[i]+pre[i-1];
    }
    reverse(pre.begin(), pre.end());

    for (int i = 0; i < n; i++)
    {
        cout<<pre[i]<<" ";
    }
    return 0;
}