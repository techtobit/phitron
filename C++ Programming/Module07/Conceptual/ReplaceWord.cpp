#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int res = str.find("Rahim");
    str.replace(res, 5, " ");
    cout<<str<<endl;
    return 0;
}