#include <bits/stdc++.h>
using namespace std;

int main()
{
    // string s = "Added And Remove";
    // string m = "X";

    // addding method in string 
    // s+=m;
    // s.append(m);
    // s.push_back('S');
    // s[15]='M'; -> will not work 

    // remove from end 
    // s.pop_back();
    // cout<<s<<endl;


    string a = "HelloWord";
    // assing fun replace a new data into any varaible 
    // a.assign("Hello");

    // erase can remove specife index using give value 
    // frist Value 4 means - from where erasing will start 
    // second Value 1 means - How much value will remove 
    // a.erase(4, 1);

    // a.replace(5,0, "RT");
    a.insert(5, "Rifat");
    cout<<a<<endl;

    return 0;
}