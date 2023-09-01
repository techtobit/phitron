#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pairs;
const int N=1e3+5;
const int INF = 1e9+5;
vector<pairs> adj[N];
vector<int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int source)
{
    priority_queue<pairs, vector<pairs>, greater<pairs> > pq;
    dist[source] = 0;

    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        visited[u] = true;
        for(pairs vPairs : adj[u])
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

// O(n+m)

int main()
{   
    int n, m;
    cin>> n>> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin>>u >>v >>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijkstra(1);

    for(int i=1; i<m; i++)
    {
        cout<< "Distance of Node " << i  << " : ";
        cout<< dist[i]<<endl;
    }
}


// input 
// 7
// 8
// 1 2 3
// 1 3 5
// 3 4 1
// 4 6 1
// 2 5 6
// 5 6 1
// 5 7 2 
// 3 7 12