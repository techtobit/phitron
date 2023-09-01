#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n; cin>>n;
    vector< vector<int>> adjMatrix(n, vector<int>(n));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>adjMatrix[i][j];
        }
    }

    vector< vector<int>> adjList(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(adjMatrix[i][j] == 1)
            {
                adjList[i].push_back(j+1);
            }
        }
    }


    //print
    for (int i = 0; i < n; i++)
    {
        cout<<"List "<< i+1<< ": ";
        if(!adjList[i].empty())
        {
            for (int j = 0; j < adjList[i].size()-1; j++)
            {
                cout<< adjList[i][j] <<" ";
            }
            cout<< adjList[i].back();
        }
        cout<<endl;
    }
    
    return 0;
}


// inputs 
// 4
// 0 0 0 1
// 1 0 0 1
// 1 1 0 0
// 0 0 1 0