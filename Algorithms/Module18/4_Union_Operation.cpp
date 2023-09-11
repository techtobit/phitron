#include<bits/stdc++.h>
using namespace std;
int parent[1000];

void dsu_set(int n)
{
    for (int i = 1; i <=n; i++)
    {
        parent[i] = -1;

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
        parent[learderB] = learderA;
    }

}

int main()
{   
    int n, e;
    cin>>n >>e;
    dsu_set(n);
    while (e--)
    {
        int a, b;
        cin>> a>> b;
        dsu_union(a, b);
    }

    
    
    return 0;
}