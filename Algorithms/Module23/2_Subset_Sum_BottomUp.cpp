#include<bits/stdc++.h>
using namespace std;

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
    
    bool dp[n+1][s+1];
    // adding 1/true for Zero th ROW & COL;
    dp[0][0] = true;

    for(int i=1; i<=n; i++)
    {
        // after Zero th Row & Col will add False;
        dp[0][i]=false;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {
            if(a[i-1] <= j)
            {
                // bool optA= dp[ i-1] [j-a[i-1]];
                // bool optB= dp[i-1][j];
                // dp[i][j] = optA || optB;

                // shortcut 
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j]= dp[i-1][j];
            }
        }
    }

    if(dp[n][s])
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}