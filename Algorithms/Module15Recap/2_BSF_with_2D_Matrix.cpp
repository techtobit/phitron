#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int N=1e3+5;
bool vis[N][N];
int dis[N][N];
vector<pi> path={{-1,0}, {1, 0}, {0, -1}, {0, 1}};
int n, m; 
bool isValid(int cI, int cJ)
{
    if(cI >=0 && cI<n && cJ >=0 && cJ<m)
    {
        return true;
    }
    else
    return false;
}

void bsf(int si, int sj)
{
    queue<pi> q;
    q.push({si, sj});
    dis[si][sj] =0;
    vis[si][sj] =true;
    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            pi p=path[i];
            int cI = pI+p.first;
            int cJ = pJ+p.second;
            if(isValid(cI, cJ) && !vis[cI][cJ])
            {
                vis[cI][cJ] = true;
                q.push({cI, cJ});
                dis[cI][cJ] = dis[pI][pJ]+1;
            }
        }
    }
    
}
int main()
{   
    cin>>n >>m;
    char a[n][m];
    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    
    int si, sj; cin>> si>> sj;
    bsf(si, sj);
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// sample 
// 2 4
// ....
// ....
// 0 1