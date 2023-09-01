#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairs; 
const int N = 1e3 + 5;
vector<string> gh;
int visited[N][N];
int n, m;

vector<pairs> direction={{0,-1},{0,1},{-1,0},{1,0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int i, int j)
{

    if (!isValid(i, j))
        return;
    if (visited[i][j])
        return;
    if (gh[i][j] == '#')
        return;

    visited[i][j] = true;


    // alternave of menual dfs(i, i-1);
    for(auto d:direction)
    {
        dfs(i+d.first, j+d.second);
    }

    // dfs(i, j - 1);
    // dfs(i, j + 1);
    // dfs(i - 1, j);
    // dfs(i + 1, j);
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        string x;
        cin >> x;
        gh.push_back(x);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (gh[i][j] == '#')
                continue;
            if (visited[i][j])
                continue;
            dfs(i, j);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

// input 
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########