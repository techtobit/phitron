#include<bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
const int N= 1005;
const int INF = 1e9+5;
vector<pi> adjList[N]; 
vector<int> dist(N, INF);
vector<bool> visited(N);

long long int n, m, w;

void  dijkstra(int source)
{
    priority_queue< pi, vector<pi>, greater<pi> >pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        visited[u] = true;
        for(pi vPairs : adjList[u])
        {
            int v=vPairs.first;
            int w = vPairs.second;
            if(visited[v]) continue;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }

    }
    
}

int main()
{   
    cin >> n>> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w; cin>> a>> b>> w;
        adjList[a].push_back({b, w});
    }
    
    int s; cin>> s;

    dijkstra(s);

    int t; cin>>t;
    for (int i = 0; i <t; i++)
    {
        int d, dw; cin>> d>> dw;
        if(dw >= dist[d])
        {
            cout<< "YES" <<endl;
        }
        else
        {
            cout<< "NO" <<endl;
        }
    }
    return 0;
}