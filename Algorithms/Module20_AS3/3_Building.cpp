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
    for(int i=1; i<=n; i++)
    {
        parent[i] = -1;
        parentSize[i]=1;
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
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if(leaderA != leaderB)
    {
        if(parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main()
{
    int n, e;
    cin>> n>> e;
    dsu_set(n);
    vector<Edge> v;
    long long res = 0;
    for(int i=1; i<=e; i++)
    {
        int a, b, w;
        cin>> a>> b>> w;
        v.push_back(Edge(a, b, w));
    }

    sort(v.begin(), v.end(), cmp);

    for(Edge val: v)
    {
        int a=val.a;
        int b=val.b;
        int w=val.w;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if(leaderA == leaderB) continue;
        res+=w;
        dsu_union(a, b);
    }

    set<int> st;

    for (int i = 1; i <=n; i++)
    {
        st.insert(dsu_find(i));
    }

    if (st.size() == 1)
        cout << res << endl;
    else
        cout << -1 << endl;
    return 0;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;

// int parent[N];
// int parentSize[N];

// class Edge
// {
// public:
//     int a, b, w;
//     Edge(int a, int b, int w)
//     {
//         this->a = a;
//         this->b = b;
//         this->w = w;
//     }
// };

// bool cmp(Edge a, Edge b)
// {
//     return a.w < b.w;
// }

// void dsu_set(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         parent[i] = i;
//         parentSize[i] = 1;
//     }
// }

// int dsu_find(int node)
// {
//     if (parent[node] == node)
//         return node;

//     return parent[node] = dsu_find(parent[node]);
// }

// void dsu_union(int a, int b)
// {
//     int leaderA = dsu_find(a);
//     int leaderB = dsu_find(b);

//     if (leaderA != leaderB)
//     {
//         if (parentSize[leaderA] > parentSize[leaderB])
//         {
//             swap(leaderA, leaderB);
//         }

//         parent[leaderA] = leaderB;
//         parentSize[leaderB] += parentSize[leaderA];
//     }
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     dsu_set(n);
//     vector<Edge> v;
//     long long res = 0;

//     for (int i = 0; i < e; i++)
//     {
//         int a, b, w;
//         cin >> a >> b >> w;
//         v.push_back(Edge(a, b, w));
//     }

//     sort(v.begin(), v.end(),cmp);

//     for (Edge val : v)
//     {
//         int a = val.a;
//         int b = val.b;
//         int w = val.w;

//         int leaderA = dsu_find(a);
//         int leaderB = dsu_find(b);
//         if (leaderA == leaderB)
//             continue;
//         res += w;

//         dsu_union(a, b);
//         if (parentSize[dsu_find(a)] == n)
//         {
//             cout << res << endl;
//             return 0;
//         }
//     }

//     cout << -1 << endl;
//     return 0;
// }
