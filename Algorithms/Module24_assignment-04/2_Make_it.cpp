#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
bool dp[N];

bool getResult(int cur, int tar )
{
    if(cur == tar) return true;
    if(cur > tar) return false;

    if(dp[cur] !=-1)
    {
        return dp[cur];
    }

    bool addNum = getResult(cur + 3, tar);
    bool addMulti = getResult(cur*2, tar);
    
    dp[cur] = addNum || addMulti;
    return dp[cur];

}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for(int i=0; i<N; i++)
        {
            dp[i]=-1;
        }

        if (getResult(1, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}