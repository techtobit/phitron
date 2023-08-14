#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int, greater<int>> mp;
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            // mp[val]++;
            mp.insert(make_pair(val, i));
        }
        // sort(mp.begin(), mp.end());
        for (auto it : mp)
        {
            cout << it.first << " ";
        }
        cout<<endl;
    }

    return 0;
}