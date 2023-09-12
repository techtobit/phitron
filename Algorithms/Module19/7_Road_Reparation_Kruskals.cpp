#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int parent[N];
int parentSize[N];
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

bool cmp(Edge a, Edge b)
{
        return a.w < b.w;
}


void dsu_set(int n)
{
    for (int i = 1; i <=n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
    
}

int dsu_find(int node)
{
    while(parent[node] !=-1)
    {
        node=parent[node];
    }
    return node;
}

void dsu_union(int a, int b)
{
    int learderA = dsu_find(a);
    int learderB = dsu_find(b);
    if(learderA != learderB)
    {
        if(parentSize[learderA] > parentSize[learderB])
        {
            // a learder
            parent[learderB] = learderA;
            parentSize[learderA] += parentSize[learderB];
        }
        else
        {
            parent[learderA] = learderB;
            parentSize[learderB] += parentSize[learderA];
        }
    }

}

int main()
{   
    int n, e;
    cin>> n>> e;
    vector<Edge> v;
    vector<Edge> ans;
    dsu_set(n);
    while (e--)
    {
        int a, b, w;
        cin>> a>> b>> w;
        v.push_back(Edge(a, b, w));
    }
    
    sort(v.begin(), v.end(), cmp);

    for(Edge val : v)
    {
        int a = val.a;
        int b = val.b;
        int w = val.w;
        // checking cycle
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        // if no cycle then push
        if(leaderA == leaderB) continue;
        ans.push_back(val);

        // connect nodes
        dsu_union(a, b);
    }

    long long sum = 0;
    for(Edge val:ans)
    {
        sum+=(long long) val.w;
    }

    if(ans.size() == n-1)
    {
        cout<< sum <<endl;
    }
    else
    {
        cout<< "IMPOSSIBLE" <<endl;
    }

    return 0;
}