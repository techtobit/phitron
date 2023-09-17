#include<bits/stdc++.h>
using namespace std;
//memorieztion
int dp[1005][1005];

int subset_sum(int n, int a[], int s)
{
    //base case
    if(n==0)
    {
        if(s==0) return true;
        else return false;
    }

    //checking it allrady visited or not.
    if(dp[n][s] != -1) return dp[n][s];


    if(a[n-1] <= s)
    {
        int op1 = subset_sum(n-1, a, s-a[n-1]);
        int op2 = subset_sum(n-1, a, s);
        return dp[n][s] = op1 + op2;
    }
    else{
        return dp[n][s] =  subset_sum(n-1, a, s);
    }
}
int main()
{   
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>> a[i];
    }

    int s;
    cin>>s;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=s; j++)
        {
            dp[i][j]=-1;
        }
    }
    
    cout<<subset_sum(n, a, s);
    return 0;
}

// input 
// 6
// 1 2 3 4 5 6
// 7