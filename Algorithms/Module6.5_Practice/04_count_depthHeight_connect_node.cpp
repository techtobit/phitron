#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int depth[N], height[N];

void dfs(int u) {

    visited[u] = true;
    for (int v : adj[u]) {
        if(visited[v]) continue;
        depth[v] = depth[v] + 1;
        dfs(v);
        if(height[v]+1 > height[u])
        height[u] = height[v]+1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    dfs(1);

    int targetNode;
    cin >> targetNode;

    cout << "Depth of " << targetNode << " = " << depth[targetNode] << endl;
    cout << "Height of " << targetNode << " = " << height[targetNode] << endl;

    return 0;
}
