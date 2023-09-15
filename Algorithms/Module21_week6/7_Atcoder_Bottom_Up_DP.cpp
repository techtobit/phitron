#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    cin>> n;
    int cost[n+1], dp[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>> cost[i];
    }

    dp[1]=0;
    dp[2]= abs(cost[2] - cost[1]);
    for(int i=3; i<=n; i++)
    {
        int choiceA = dp[i-2] + abs(cost[i]-cost[i-2]);
        int choiceB = dp[i-1] + abs(cost[i] - cost[i-1]);
        dp[i]= min(choiceA, choiceB);
    }

    cout<<dp[n]<<endl;
    return 0;
}