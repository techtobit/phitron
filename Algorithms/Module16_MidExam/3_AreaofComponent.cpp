#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int N=1005;
char matrix[N][N];
bool vist[N][N];
int n, m;
int minC = INT_MAX;
int cnt=0;

vector<pi> path = {{-1,0}, {1, 0}, {0, -1}, {0,1}};

bool isValid(int cI, int cJ)
{
    if(cI >=0 && cI<n && cJ >=0 && cJ<m )
    {
        return true;
    }
    else
    return false;
}
void dfs(int i, int j)
{
    vist[i][j] = true;
    cnt++;
    for(pi p: path)
    {
        int cI = i+p.first;
        int cJ = j+p.second;
        if(isValid(cI, cJ) && !vist[cI][cJ] && matrix[cI][cJ]=='.' )
        {
            dfs(cI, cJ);
        }
    }
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

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!vist[i][j] && matrix[i][j] == '.')
            {  
                cnt=0;
                dfs(i, j); 
                minC= min(cnt, minC);
            }
        }
    }

    if (minC == INT_MAX) 
    {
        cout << "-1" << endl;
    } else 
    {
        cout << minC << endl;
    }
    return 0;
}