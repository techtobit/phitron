#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairs;
const int N=1e5+5;
const int INF=1e9+7;
vector<pairs> g[N];
vector< pair< pairs, int> > listOfEdges;
int d[N];
int n, m;

void belman_ford(int s)
{
    for(int i=1; i<=n; i++)
        d[i] = INF;
        d[s] = 0;

    for(int i=1; i< n; i++)
    {
        for(int u=1; u<=n; u++)
        {
            for(pairs vpair: g[u])
            {
                int v=vpair.first;
                int w=vpair.second;
                if(d[u] !=INF && d[v] > d[u]+w)
                {
                    d[v] = d[u]+w;
                }
            }
        }
    }
}
int main()
{   
    cin>> n >>m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin>> u>> v>> w;
        g[u].push_back({v,w});
    }
    
    // while (m--)
    // {
    //     int u, v, w;
    //     cin>> u>> v>> w;
    //     g[u].push_back({v,w});
    // }

    belman_ford(1);

    for (int i = 1; i <=n ; i++)
    {
        cout<< "Distance of " << i;
        cout<< ": " << d[i] <<endl;
    }
    
    
    return 0;
}  

// Input 
// 4
// 4
// 1 2 4
// 1 3 3
// 3 4 5
// 4 2 -10
