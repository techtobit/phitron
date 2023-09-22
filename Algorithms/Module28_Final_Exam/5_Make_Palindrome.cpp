//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int dp[n][n];

        for (int i = 0; i < n; i++)
            dp[i][i] = 0;

        for (int k = 2; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        if (dp[0][n - 1] == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << dp[0][n - 1] + 1 << endl;
        }
    }

    return 0;
}
