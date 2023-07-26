#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    queue<int> qe;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        st.push(a);
    }

    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        qe.push(b);
    }


    bool flag = true;

    if (st.size() == qe.size())
    {
        while (!st.empty() || !qe.empty())
        {
            if (st.top() != qe.front())
            {
                flag = false;
                break;
            }
            st.pop();
            qe.pop();
        }
    }
    else
    {
        flag = false;
    }

    if (flag == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}