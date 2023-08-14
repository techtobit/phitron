#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n; cin>>n;
    priority_queue<int, vector<int>, greater<int>>pq;
    while (n--)
    {
        int val;
        cin>>val;
        pq.push(val);
    }
    
    int q; cin>>q;
    while (q--)
    {
        int c; cin>>c;
        if(c==0)
        {
            int val; cin>>val;
            pq.push(val);
            cout<<pq.top()<<endl;
        }
        else if(c==1)
        {
            if(!pq.empty())
            {
                cout<<pq.top()<<endl;
            }
            else
            {
                cout<<"Empty"<<endl;
            }
        }
        else if(c==2)
        {
            if(!pq.empty())
            {
                pq.pop();
                if(!pq.empty())
                {
                    cout<<pq.top()<<endl;
                }
                else
                {
                    cout<<"Empty"<<endl;
                }
            }
            else
            {
                cout<<"Empty"<<endl;
            }
        }
    }
    
    return 0;
}