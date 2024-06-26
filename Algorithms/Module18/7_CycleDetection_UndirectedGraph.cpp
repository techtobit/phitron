#include<bits/stdc++.h>
using namespace std;
// input 
// 5 5
// 4 5
// 1 2
// 2 5
// 1 4
// 2 3
int parent[1000];
int parentLevl[1000];

void dsu_set(int n)
{
    for (int i = 1; i <=n; i++)
    {
        parent[i] = -1;
        parentLevl[i] = 0;
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
        if(parentLevl[learderA] > parentLevl[learderB])
        {
            parent[learderB] = learderA;
        }
        else if(parentLevl[learderB] > parentLevl[learderA])
        {
            parent[learderA] = learderB;
        }
        else
        {
            parent[learderB] = learderA;
            parentLevl[learderA]++;
        }
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
        int learderA = dsu_find(a);
        int learderB = dsu_find(b);
        if(learderA == learderB)
        {
            cout<<"Cycel Dected In Between "
            << a <<" "<< b<<endl;
        }
        else
        {
            dsu_union(a,b);
        }
    }
    
    return 0;
}