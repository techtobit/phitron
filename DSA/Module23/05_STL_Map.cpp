#include<bits/stdc++.h>
using namespace std;

int main()
{   
    map<string, int> mp;
    // mp.insert({"Sakib", 75});
    // mp.insert({"Rokib", 19});

    // for(auto it=mp.begin(); it !=mp.end(); it++)
    // {
    //     cout<<it->first<<" "
    //     <<it->second <<endl;
    // }

    // method 2 
    mp["Sakib"] = 75;
    mp["Rakib"] = 20;
    mp["Abid"] = 80;
    for(auto it=mp.begin(); it !=mp.end(); it++)
    {
        cout<<it->first<<" "
        <<it->second <<endl;
    }
    // cout<<mp["Sakib"]<<endl;
    return 0;
}