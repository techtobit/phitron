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

void prims(int s)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    vector<Edge> edgeList;
    pq.push(Edge(s, s, 0));
    while(!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int a = parent.a;
        int b = parent.b;
        int w = parent.w;
        if(vis[b]) continue;
        vis[b] = true;
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
    for(Edge val: edgeList )
    {
        cout<< val.a<<" "<< val.b <<" "<<val.w<<endl;
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

    prims(1);
    
    return 0;
}

// input 
// 8 11
// 1 5 2
// 1 2 4
// 1 4 10
// 5 4 5
// 2 4 8
// 2 3 18
// 4 3 11
// 4 8 9
// 4 7 11
// 7 6 1
// 8 6 2