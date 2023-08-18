#include<bits/stdc++.h>
using namespace std;
int Search(int nums[],int l, int r, int x)
{
    if(l==x) return 1;
    while (left <= right)
    {
        int mid=(l+r)/2;
        if(nums[mid] ==x)
        return mid;
        else if(nums[mid]<x)
        l=mid+1;
        else
        r=mid-1;
    }
    return -1;
    

};

int main()
{   
    int t; cin>>t;
    // vector<int> nums(t);
    int nums[t];
    for(int i=0; i<t; i++)
    {
        cin>>nums[i];
    }

    int x; cin>>x;
    int idx= Search(nums,0, t-1, x);

    // for(int i=0; i<t; i++)
    // {
    //     if(nums[i] == x)
    //     idx=i;
    // }

    if(idx >= 0)
    cout<<idx;
    else 
    cout<<"Not Found";
    
    
    return 0;
}



