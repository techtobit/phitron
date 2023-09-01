#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int depth[N];

void dfs(int u, int parent) {
    depth[parent] + 1;

    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
        }
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

    depth[0] = 0; 
    dfs(1, 0);

    int targetNode;
    cin >> targetNode;

    cout << "Depth of " << targetNode << " = " << depth[targetNode] << endl;

    return 0;
}
