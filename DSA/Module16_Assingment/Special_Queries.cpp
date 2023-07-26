#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<string> myQueue;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int c;
        cin >> c;
        if (c == 0)
        {
            string name;
            cin >> name;
            myQueue.push(name);
        }
        else if (c == 1 && myQueue.empty())
        {
            cout << "Invalid" << endl;
        }
        else if (c == 1)
        {
            cout << myQueue.front() << endl;
            myQueue.pop();
        }
    }

    return 0;
}