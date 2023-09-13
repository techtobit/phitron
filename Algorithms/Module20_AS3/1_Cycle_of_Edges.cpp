#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
int parent[N];
int parentSize[N];
vector<int>adjList[N];
bool vis[N];
int ans=0;

void dsu_set(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i]=-1;
        parentSize[i]=1;
    }
}

int dsu_find(int node)
{
    while (parent[node] !=-1)
    {
        node = parent[node];
    }
    return node;
    
}

void dsu_union(int a, int b)
{
    int learderA = dsu_find(a);
    int learderB = dsu_find(b);

    if(learderA == learderB)
    {
        ans++;
    }
    else if(learderA != learderB)
    {
        if(parentSize[learderA] > parentSize[learderB])
        {
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
    int n, e; cin>> n>> e;
    dsu_set(n);
    while (e--)
    {
        int a, b; cin>> a>> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        dsu_union(a, b);
    }
    cout<< ans;
    
    return 0;
}

// 5 7
// 1 2
// 2 3
// 3 4
// 4 5
// 4 1
// 2 4
// 5 3