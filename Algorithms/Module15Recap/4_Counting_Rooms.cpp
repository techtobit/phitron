#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int N=1e3+5;
bool vis[N][N];
vector<pi> path={{-1,0}, {1, 0}, {0, -1}, {0, 1}};
int n,m;
char a[N][N];

bool isValid(int cI, int cJ)
{
    if(cI >=0 && cI<n && cJ >=0 && cJ<m
        && a[cI][cJ] == '.'
    )
    {
        return true;
    }
    else
    return false;
}


void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        pi p = path[i];
        int ci=si+p.first;
        int cj=sj+p.second;
        if(isValid(ci, cj) && !vis[ci][cj])
        dfs(ci, cj);
    }
    
}
int main()
{   
    cin>>n >>m;
    // int a[n][m];
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>> a[i][j];
        }
        
    }

    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j] && a[i][j] =='.')
            { 
                cnt++;
                dfs(i,j);
            }
        }
    }
    
    cout<< cnt<< endl;
    return 0;
}