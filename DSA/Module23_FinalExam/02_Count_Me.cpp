#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string sentence;
        getline(cin, sentence);
        string ans;
        int maxVal = 0;
        string word;
        stringstream ss(sentence);
        map<string, int> mp;
        while (ss >> word)
        {
            mp[word]++;
            if (mp[word] > maxVal)
            {
                ans = word;
                maxVal = mp[word];
            }
        }

        cout<<ans<<" "<<maxVal<<endl;
    }

    // cout<<maxVal<<endl;
    // for (auto it = mp.begin(); it != mp.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    return 0;
}