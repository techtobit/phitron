#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        cout<< v<<" "<<endl;
        DFS(v);
    }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = visited[u] + 1;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cc = 0;

    for (int i = 1; i <=n; i++)
    {
        if (visited[i])
            continue;
        DFS(i);
        // BFS(i);
        cc++;
    } 

    // cout<<"Connected Components: "<<cc<<endl;
    return 0;
}

// Input 
// 12  
// 11
// 1 2
// 1 3
// 1 10
// 2 4
// 2 5
// 3 9
// 5 6 
// 5 7
// 7 8
// 10 11
// 10 12

// Input 2 
// 7
// 5
// 1 2
// 1 3
// 2 3
// 2 4
// 5 6
