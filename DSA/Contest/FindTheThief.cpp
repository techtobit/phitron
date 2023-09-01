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
        int odd[n];
        for (int j = 0; j < n; j++)
        {
            cin >> odd[j];
        }
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result ^= odd[i];
        }

        cout<<result<<endl;
    }
    return 0;
}