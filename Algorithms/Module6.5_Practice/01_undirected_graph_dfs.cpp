#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u]= true;
    for(int v:adj[u])
    {
        if(visited[v]) continue;
        dfs(v);
        
    }
    reverse(adj[u].begin(), adj[u].end());
    cout<<u<<endl;
}

int main()
{   
    int n, m;
    cin>>n>>m;
    for(int i=0; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    return 0;
}