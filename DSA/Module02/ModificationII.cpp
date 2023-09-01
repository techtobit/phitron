#include<bits/stdc++.h>
using namespace std;

int main()
{
    // replace in build algo
    vector<int>v={1,2,3,4,5,2,4,6,2,5,2};
    // replace will take the value of index to replace
    // and take the new value to replace old one.
    // begin and end will find 2 in the vector and
    // replace all 2 by 100 
    // replace(v.begin(),v.end(), 2,100);


    // will not replace last 2
    // replace(v.begin(),v.end()-1, 2,100);


    // for(int x:v){
    //     cout<<x<<" ";
    // }


    // find 
    // vector<int>::iterator it;
    // it = find(v.begin(), v.end(), 3);

    auto it = find(v.begin(), v.end(), 3);
    cout<<*it;
    
    return 0;
}