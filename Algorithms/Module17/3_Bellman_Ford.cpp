#include <bits/stdc++.h>
using namespace std;

// input
// 3 3
// 1 2 2
// 3 1 -1
// 2 3 -3

class Edge
{
public:
    int v;
    int u;
    int w;

    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edge eg(a, b, w);
        v.push_back(eg);
        ;
    }

    int dis[n + 1];
    // takeing distance total node + 1;
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
        // addeing Infinte value to node edge
    }
    dis[1] = 0;
    // addeing source node to 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];

            int a = ed.u;
            int b = ed.v;
            int w = ed.w;

            if (dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << "  => " << dis[i] << endl;
    }
    return 0;
}