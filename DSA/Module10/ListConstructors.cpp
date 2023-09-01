#include<bits/stdc++.h>
using namespace std;
int main()
{   

    // -- Create New List -- // 

    // list<int>myList
    // list<int>myList(10);
    // cout<<myList.size()<<endl;

    // list<int>myList(10, 5);
    // //list size 10 and all will fill up with 5

    // -- Copy From List -- // 
    // list<int>myList2 = {1, 2, 3, 4, 5};
    // list<int>myList(myList2);

    // -- copyFrom An Array -- // 
    // int a[5] = {10, 20, 30, 40, 50};
    // list<int>myList(a, a+5);
    // In Array  a-> frist pointer.
                // a+n -> last pointer 

    vector<int> v = {100, 200, 300};
    list<int>myList(v.begin(), v.end());
    // for (auto it = myList.begin(); it !=myList.end(); it++)
    // {
    //     cout<< *it << endl;
    // }

    // if no needed index and pointer then can 
    // use frequency array for geting valu.

    for(int val:myList)
    {
        cout<< val << endl;
    }
    return 0;
}