#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vis[N];
int dis[N];
vector<int> v[N];

void dfs(int i)
{
    vis[i]=true;
    for(int child : v[i])
    {
        if(!vis[child])
        dfs(child);

    }
}
int main()
{   
    int n, e;
    cin>> n>> e;
    while (e--)
    {
        int a, b;
        cin >> a>> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int cnt =0;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        cnt++;
        dfs(i);
    }
    
    cout<<cnt<<endl;
    return 0;
}

// input 
// 5 2
// 1 2
// 3 4