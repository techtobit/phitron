#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int N = 1e5+5;
vector<pi> adjList[N];
bool vis[N];
class Edge
{
    public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

class cmp
{
    public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};

void prims(int s, int n)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    vector<Edge> edgeList;
    pq.push(Edge(s, s, 0));
    int count = 0;

    while(!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int a = parent.a;
        int b = parent.b;
        int w = parent.w;
        if(vis[b]) continue;
        vis[b] = true;
        count++;
        edgeList.push_back(parent);
        for(int i=0; i<adjList[b].size(); i++)
        {
            pi child = adjList[b][i];
            if(!vis[child.first])
            {
                pq.push(Edge(b, child.first, child.second));
            }
        }
    }

    // remveing extra 1, 1, 0 pair.
    edgeList.erase(edgeList.begin());
    long long sum =0;
    for(Edge val: edgeList )
    {
        sum+= (long long)(val.w); // (long long)- converting val.w int val to long val
    }

    if(count == n)
    {
        cout<< sum <<endl;
    }
    else
    {
        cout<< "IMPOSSIBLE" <<endl;
    }
}

int main()
{  
    int n, e;
    cin>> n>> e;
    while (e--)
    {
        int a, b, w; 
        cin>> a>> b>> w;
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }

    prims(1, n);
    
    return 0;
}

// pb link 
// https://cses.fi/problemset/task/1675/
// input 
// 5 6
// 1 2 3
// 2 3 5
// 2 4 2
// 3 4 8
// 5 1 7
// 5 4 4