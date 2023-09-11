#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int INF = 1e7;
const int N = 1e3+5;
int dis[N];
vector<pi> adjList[N];
vector<pair<pi, int>> listOfEdge;

int n, e;

void bfs(int s)
{
    for(int i=0; i<=n; i++)
    {
        dis[i] = INF;
        dis[s] =0;
    }

    for(int i=1; i<=n; i++)
    {
        for(int u=1; u<=n; u++)
        {
            for(pi vPair: adjList[u])
            {
                int v = vPair.first;
                int w = vPair.second;
                if(dis[u] !=INF && dis[v] > dis[u] +w)
                {
                    dis[v] = dis[u]+w;
                }
            }
        }
    }
}
int main()
{   
    cin>> n>> e;
    for(int i=1; i<=e; i++)
    {
        int u, v, w;
        adjList[u].push_back({v,w});
    }

    bfs(1);


    for (int i = 1; i <=n ; i++)
    {
        cout<< "Distance of " << i;
        cout<< ": " << dis[i] <<endl;
    }
    
    
    
    return 0;
}