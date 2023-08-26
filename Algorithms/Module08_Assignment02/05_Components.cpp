#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> visited(N, false);
vector<int> ans;

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    int count = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        count++;
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
        if(count> 1)
        ans.push_back(count);
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
        adj[v].push_back(u);
    }


    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }

    sort(ans.begin(), ans.end());
    for (int v : ans)
    {
        cout << v << " ";
    }

    return 0;
}

