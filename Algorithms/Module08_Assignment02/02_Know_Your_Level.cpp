#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> visited(N, false);
vector<int> level(N, -1);
vector<int> ans;

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    level[u] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    if (n == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int l;
    cin >> l;

    bfs(0);

    ans.clear();
    for (int i = 0; i < N; i++)
    {
        if (level[i] == l)
        {
            ans.push_back(i);
        }
    }

    if (ans.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        sort(ans.begin(), ans.end());
        for (int v : ans)
        {
            cout << v << " ";
        }
    }

    return 0;
}
