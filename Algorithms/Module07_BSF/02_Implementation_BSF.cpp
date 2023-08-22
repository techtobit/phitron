#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> adj[N];
bool visited[N];
int level[N];

void bsf(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s]=0;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<"Node: " <<u<<endl;

        for(int v: adj[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v]= level[u]+1;
        }
    }
    
}
int main()
{   
    int n, m;
    cin>> n>> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bsf(1);
    cout<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout<<"level: "<<level[i]<<endl;
    }
    
    return 0;
}