#include<bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if(n==0 || n == 1)
    {
        return 1;
    }
    int ansA = fibo(n-1);
    int ansB = fibo(n-2);
    // f(n) = f(n-1) + (n-2) 
    // f(5) = f(5-1) + (5-2); 
            //   4 + 3 = 8
    // f(5) =8 
    return ansA + ansB;
}

int main()
{   
    int n; cin>>n;
    cout<< fibo(n);
    return 0;
}