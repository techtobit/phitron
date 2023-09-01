#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 4;
vector<int> adj[N];
vector<bool> visited(N, false);
int main()
{
    int n, m;
    cin >> n >> m;

    // if (n == 0)
    // {
    //     cout << -1 << endl;
    //     return 0;
    // }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int k;
    cin >> k;

    int s = adj[k].size();
    cout << s;

    return 0;
}

// input 
// 6 5
// 0 1
// 0 2
// 0 3
// 2 3
// 4 5
// 2