#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main()
{   
    int e;
    cin>>e;
    for (int i = 0; i < e; i++)
    {
        int a, b; cin>> a>>b;
        q.push({a, b});
    }

    while (!q.empty())
    {
        pair<int, int> ans = q.top();
        q.pop();
        cout<< ans.first<<" "<< ans.second <<endl;
    }

    return 0;
}