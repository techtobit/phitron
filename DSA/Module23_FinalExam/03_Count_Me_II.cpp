#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {

        map<int, int> mp;
        int n;
        cin >> n;
        int maxVal = 0;
        int ans;
        while (n--)
        {
            int val;
            cin >> val;
            mp[val]++;

            if (mp[val] > maxVal)
            {
                maxVal = mp[val];
                ans = val;
            }

            else if (mp[val] >= maxVal)
            {
                maxVal = mp[val];
                if (mp[val] == maxVal)
                {
                    ans = max(ans, val);
                }
                
            }
        }

        cout << ans << " "<<maxVal<< endl;
    }

    return 0;
}