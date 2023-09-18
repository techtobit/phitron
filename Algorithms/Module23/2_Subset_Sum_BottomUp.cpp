#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        int sum = 1000 - m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool dp[n + 1][N];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                dp[i][j] = false;
            }
        }

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[n][sum])
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
