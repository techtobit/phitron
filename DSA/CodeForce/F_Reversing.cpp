#include<bits/stdc++.h>
using namespace std;

int main()
{   int n; 
    cin>>n;
    cin.ignore();
    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        for(int j = i+1; j<n; j++){
            swap(a[i], a[j]);
        }
    }
    for(int i = 0; i< n ; i++){
        cout<<a[i]<< " ";
    }
    
    return 0;
}