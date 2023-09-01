#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int> adj[N];
bool visited[N];

bool dfs(int s, int p=-1) //p - perant of curent node.
{
    bool cycleExists = false;
    visited[s] = true;
    for(int v:adj[s])
    {
        if(v==p) continue;
        if(visited[v]) return true;
        cycleExists |= dfs(v,p); // cycleExists = cycleExists | dfs(v,p);
    }
    return cycleExists;
};

int main()
{   
    int n, m;
    cin >>n >>m;
    for (int i =1; i <=m; i++)
    {
        int u, v;
        cin >>u >>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    // if dont have separate cycle or node list
    /*if(dfs(1))
    {
    // Input 
    // 5
    // 5 
    // 1 2
    // 2 3
    // 3 5
    // 5 4
    // 4 2
        cout<<"Cycle Detected";
    }
    else
    cout<< "No Cycle Detected";
    */

    // if have separate cycle of nodes & list 
    bool isCycle=false;
    for(int i=1; i<=n; i++)
    {
        /*
        Inputs
        8
        7
        1 2
        2 3
        3 5
        5 4
        differn cycle input like 
        6 7
        6 8
        7 8*/
        if(visited[i]) continue;
        isCycle |= dfs(i);
    }

    if(isCycle)
    cout<<"Cycle Detected!";
    else
    cout<<"Cycle Not Detected";

    return 0;
}


