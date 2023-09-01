#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int> adj[N];
vector<bool> vistited(N, false);

void dfs(int u)
{
    vistited[u]=true;
    for(int v:adj[u])
    {
        if(vistited[v]) continue;
        dfs(v);
    }
}

int main()
{   
    int n, m; cin>> n>> m;
    for(int i=0; i<m; i++)
    {
        int u, v; cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> newRoot;
    for(int i=1; i<=n; i++)
    {
        if(vistited[i] ) continue;
        newRoot.push_back(i);
        dfs(i);
    }

    // check nodes 
    // for(int r:newRoot)
    // cout<<r<<" ";

    cout<< newRoot.size()-1 <<endl;
    for(int i=1; i<newRoot.size(); i++)
    cout<< newRoot[i-1] <<" "<<newRoot[i] <<endl;
    return 0;
}

// input 
// 8 4
// 1 2
// 3 4
// 5 6
// 5 7