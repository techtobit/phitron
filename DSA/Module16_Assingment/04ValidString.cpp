#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        stack<char> valid;
        string ch;
        cin >> ch;
        // cout<<ch<<endl;
        for (int i = 0; i < ch.size(); i++)
        {
            // cout<<ch[i]<<' ';
            if (!valid.empty())
            {
                if ((ch[i] == 'A' && valid.top() == 'B') || (valid.top() == 'A' && ch[i] == 'B'))
                {
                    valid.pop();
                }
                else
                {
                    valid.push(ch[i]);
                }
            }
            else
            {
                valid.push(ch[i]);
            }
        }

        if (valid.size() == 0)
        {
            cout << "YES" << endl;
        }
        else if (valid.size() > 0)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}