#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+3;

int main()
{   
    long long int n;
    cin>>n;
    long long int arr[n+1];
    arr[0]=1;
    arr[1]=1;

    for(int i=2; i<=n; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout<< arr[n];

    return 0;
}