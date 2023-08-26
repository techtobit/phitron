#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 4;
vector<int> adj[N];
vector<bool> visited(N, false);
vector<int> ans;

void dfs(int u)
{
    visited[u]=true;

    for(int v: adj[u])
    {
        if(visited[v]) continue;
        dfs(v);
        ans.push_back(v);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    int k;
    cin >> k;

    dfs(k);

    int s = ans.size();
    cout << s;


    return 0;
}

// input 
// 6 5
// 0 1
// 0 2
// 2 3
// 3 0
// 4 5
// 2