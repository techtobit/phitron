#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];

int knapsack(int n, int s, int v[], int w[])
{
    if(n==0 || s==0) return 0;
    
    if(dp[n][s] !=-1) return dp[n][s];
    
    if(w[n-1] <= s)
    {
        int opA= knapsack(n-1, s-w[n-1], v, w) + v[n-1];
        int opB= knapsack(n-1, s, v, w);
        dp[n][s]= max(opA, opB);
    }
    else
    {
        dp[n][s]= knapsack(n-1, s, v, w);
    }

    return dp[n][s];
}


int main()
{   
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n, s;
        cin>>n >>s;
        int w[n], v[n];

        for(int i=0; i<n; i++)
        {
            cin>>w[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
        }

        for (int i = 0; i <=n; i++)
        {
            for(int j=0; j<=s; j++)
            {
                dp[i][j] = -1;
            }
        }
        


        // for(int i=0; i<n; i++)
        // {
        //     cout<<w[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0; i<n; i++)
        // {
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        
        cout<< knapsack(n, s, v, w)<<endl;

    }
    return 0;
}