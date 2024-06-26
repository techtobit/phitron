#include<bits/stdc++.h>
using namespace std;
const int INF=1e7;

int main()
{   
    int n, e;
    cin>> n>> e;
    int dis[n+1][n+1];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dis[i][j] = INF;
            if(i==j)
            {
                dis[i][j] =0;
            }
        }
    }

    while(e--)
    {
        int a, b, w; 
        cin>> a>> b>> w;
        dis[a][b] =w;
    }

    // before update 
    for (int i =1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if(dis[i][j] == INF) 
            cout<< "INF" << " ";
            else
            cout<< dis[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    // Main Floyd_Warshall Algo imp.
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dis[i][k] + dis[j][k] < dis[i][j])
                {
                    dis[i][j]=dis[i][k] + dis[j][k];
                }
            }
        }
    }

    cout<< "After Update"<<endl;
    // after update 
        for (int i =1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if(dis[i][j] == INF) 
            cout<< "INF" << " ";
            else
            cout<< dis[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}


// input 
// 4 6
// 1 2 3
// 2 1 2
// 1 4 5
// 4 3 2
// 3 2 1
// 2 4 4 