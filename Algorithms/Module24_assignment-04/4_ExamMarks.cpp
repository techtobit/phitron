#include <bits/stdc++.h>
using namespace std;
bool dp[1005][1005];

bool sumset_sum(int n, int a[], int m)
{
    if(n==0)
    {
        if(m==0) return true;
        else return false;
    }

    if(dp[n][m] !=false) return dp[n][m];
    if(a[n-1] <= m)
    {
        bool opA= sumset_sum(n-1, a, m-a[n-1]);
        bool opB= sumset_sum(n-1, a, m);
        return  opA || opB;
    }
    else
    {
        return dp[n][m] = sumset_sum(n-1, a, m);
    }

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int sum = 1000-m;

        if(sumset_sum(n, a, sum))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}