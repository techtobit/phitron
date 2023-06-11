#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    stringstream ss(str);
    string word;

    while (ss>>word)
    {
        cout<<word<<endl;
    }
    
    return 0;
}