#include <bits/stdc++.h>
using namespace std;
// to make dynamic pair to use multiple times 
typedef pair<int, int> pairs; 
const int N = 1e3 + 5;
vector<string> gh;
int visited[N][N];
int level[N][N];
pairs parent[N][N];
int n, m;

//to make dynamic left right movement
vector<pairs> direction={{0,-1},{0,1},{-1,0},{1,0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pairs>q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] =0;

    while (!q.empty())
    {
            pairs unpair = q.front();
    int i = unpair.first;
    int j = unpair.second;
    q.pop();

    for(auto d:direction)
    {
        int ni=i+d.first;
        int nj=j+d.second;

        if(isValid(ni, nj) && !visited[ni][nj] && gh[ni][nj] !='#')
        {
            q.push({ni, nj});
            visited[ni][nj]=true;
            level[ni][nj] = level[i][j]+1;
            parent[ni][nj] = {i, j};
        }
    }
    }
    
}

int main()
{

    int si, sj, di, dj;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        string x;
        cin >> x;
        for(int j=0; j<m; j++)
        {
            if(x[j]=='A')
            si=i, sj=j;
            if(x[j]=='B')
            di=i, dj=j;
        }
        gh.push_back(x);
    }

    bfs(si, sj);
    if(level[di][dj] !=0)
    {
        cout<<"YES\n";
        cout<< level[di][dj] <<endl;
    }
    else
        cout<<"NO\n";

    vector<pairs> path;
    pairs curr = {di, dj};
    while (!(curr.first==si && curr.second==sj))
    {
        path.push_back(curr);
        curr = parent[curr.first][curr.second];
    }


    path.push_back({si, sj});
    reverse(path.begin(), path.end());

    for(auto p:path)
    {
        cout<< p.first <<" "<< p.second ;
        cout<<endl;
    }
    

    for(int i=1; i<=path.size()-1; i++)
    {
        //path[i-1] -> path[i];
        if(path[i-1].first == path[i].first)
        {
            if(path[i-1].second == path[i].second-1)
            cout<<"R";
            else
            cout<<"L";
        }
        else
        {       
            if(path[i-1].first == path[i].first-1)
            cout<<"D";
            else
            cout<<"U";
        }
        }
    return 0;
}

// input 
// 5 8
// ########
// #.A#...#
// #.##.#B#
// #......#
// ########