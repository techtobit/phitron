#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int N=1e3+5;
char matrix[N][N];
bool vist[N][N];
int n, m;
int si, sj, di, dj;
vector<pi> path = {{-1,0}, {1, 0}, {0, -1}, {0,1}};

bool isValid(int cI, int cJ)
{
    if(cI >=0 && cI<n && cJ >=0 && cJ<m && matrix[cI][cJ]=='.')
    {
        return true;
    }
    else
    return false;
}

void bfs(int si, int sj, int di, int dj)
{
    queue<pi> q;
    q.push({si, sj});
    vist[si][sj] = true;

    while (!q.empty())
    {
        pi current = q.front();
        int pI = current.first;
        int pJ = current.second;
        q.pop();

        for(pi p:path)
        {
            int cI = pI+p.first;
            int cJ = pJ+p.second;
            if(isValid(cI, cJ) && !vist[cI][cJ])
            {
                vist[cI][cJ] = true;
                q.push({cI, cJ});
            }
        }
    }

    if(vist[di][dj])
        cout<<"YES" <<endl;
    else
        cout<<"NO" <<endl;
    
}
int main()
{   
    cin>> n>> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>> matrix[i][j];
        }
    }

    cin>> si>> sj>> di>> dj;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            vist[i][j] = false;
        }
    }

    bfs(si, sj, di, dj);
    
    return 0;
}