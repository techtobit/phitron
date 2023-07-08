#include<bits/stdc++.h>
using namespace std;

int main()
{   int n; 
    cin>>n;
    cin.ignore();
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        

    }

    for (size_t i = 0; i < n; i++)
    {
        cin>>b[i];
    }

    
    // c.reserve(a.size()+b.size());
    vector<int> c = b;
    // c.insert(c.end(), b.begin(), b.end());
    c.insert(c.end(), a.begin(), a.end());
    
    for(int x:c){
        cout<<x<<" ";
    }
    
    return 0;
}