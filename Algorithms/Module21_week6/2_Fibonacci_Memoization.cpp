#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int saveVisiteValue[N];

int fibo(int n)
{
    if(n<=1) return 1;
    
    // checking value visited & saved or not?
    if(saveVisiteValue[n] != -1) //default value -1;
    {
        return saveVisiteValue[n];
    }

    int ansA = fibo(n-1);
    int ansB = fibo(n-2);
    saveVisiteValue[n] = ansA+ansB;
    return saveVisiteValue[n];
}

int main()
{   
    int n; cin>>n;
    for(int i=1; i<=n; i++)
    {
        saveVisiteValue[i] = -1;
    }
    cout<< fibo(n);
    return 0;
}