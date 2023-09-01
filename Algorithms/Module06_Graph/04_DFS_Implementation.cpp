#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> adj[N];
bool visited[N];
void dfs(int u)
{
    // section 1: actions just after entering node n u;
    visited[u]=true;
    cout<<"Vistiting Node:" <<u<<endl;
    for(int v: adj[u])
    {
        //section 2: actions before entring a new neighbor;
        if(visited[v]) continue;
        dfs(v);
        //sections 3: actions after exting a neighbor;
    }
    //sections 4: actions before exiting node u;
}
int main()
{   
    int n, m;
    cin>>n >>m;
    for (int i = 1; i <=m; i++)
    {
        int u, v;
        cin>>u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    
    return 0;
}

//INPUTS :
// 10
// 9
// 1 2
// 1 3
// 1 10
// 2 4
// 3 5
// 3 6
// 4 7
// 4 8
// 6 9