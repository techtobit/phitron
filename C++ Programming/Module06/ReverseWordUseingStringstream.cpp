#include <bits/stdc++.h>
using namespace std;


// //general way to print string
// int main()
// {
//     string s;
//     getline(cin, s);
//     stringstream ss(s);
//     string word;
//     while (ss>>word)
//     {
//         cout<<word<<endl;
//     }
    

//     return 0;
// }


// How to print in Revers Way 

void fun(stringstream & ss)
{
    string word;
    if(ss>>word)
    {
        // cout<<word<<endl;
        // fun(ss);

        //reverse print 
        fun(ss);
        cout<<word<<endl;
    }
    
}

int main()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    fun(ss);
    return 0;
}