#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int N = 1005;
int grid[N][N];
bool vist[N][N];
int dist[N][N];
int n, m, si, sj, qi, qj;

vector<pi> path = {{-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-1, -2}, {1, -2}, {-2, 1}, {-2, -1}};

bool isValid(int cI, int cJ)
{
    return (cI >=0 && cI < n && cJ >=0 && cJ < m);
}

void bfs(int si, int sj)
{
    queue<pi> q;
    q.push({si, sj});
    dist[si][sj] = 0;
    vist[si][sj] = true;

    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();

        for(int i=0; i<8; i++)
        {
            pi p = path[i];
            int cI = pI+p.first;
            int cJ = pJ+p.second;

            if(isValid(cI, cJ) && !vist[cI][cJ])
            {
                vist[cI][cJ] = true;
                q.push({cI, cJ});
                dist[cI][cJ] = dist[pI][pJ] + 1;
            }
        }
    }
    

}
int main()
{

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {   
            for (int j = 0; j < m; j++)
            {
                vist[i][j] = false;
                dist[i][j] = -1;
            }
        }

        cin >> si >> sj >> qi >> qj;
        bfs(si, sj);

        if(dist[qi][qj] == -1)
        cout<< "-1"<<endl;
        else
        cout<< dist[qi][qj] <<endl;
    }
    return 0;
}

