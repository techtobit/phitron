#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
int adjMatrix[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    for (int u = 1; u <= n; u++)
    {
        for (int v : adjList[u])
        {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// input 
// 3
// 5
// 1 2
// 2 3
// 1 3
// 3 1
// 3 2
