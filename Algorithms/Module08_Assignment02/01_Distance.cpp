#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> visited(N, 0);


void BFS(int u)
{
    queue<int>q;
    q.push(u);
    visited[u]=1;

    while (!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int v:adj[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = visited[u]+1;
        }
    }
    
}

int main()
{
    int n, e; cin>>n>>e;
    for (int i = 0; i<e; i++)
    {
        int u, v; cin>>u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int s, d;
        cin >> s >> d;
        
        for(int j=0; j<=N; j++)
        {
            visited[j]=0;
        }

        BFS(s);
        int distance = visited[d] -1;
        cout<< distance<<endl;
    }

    return 0;
}