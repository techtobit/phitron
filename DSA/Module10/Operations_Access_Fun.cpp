#include<bits/stdc++.h>
using namespace std;
int main()
{   
    list<int>myList = {10, 20, 30, 40, 50, 20};

    //remove all 20s from list.
    // myList.remove(20);

    // will sort all valus in acending order 
    // myList.sort();

    //will short in decending order
    // myList.sort(greater<int>());

    //Remove duplicate Value from list
    // Note : if value not shorted then it will only
    // remove those value whom are staying after or 
    // before the value 10 10.
    // But can't delete  from random position 10 20 10
    // for that must have to use sort fun;
    // myList.sort();
    // myList.unique();


    //revers list 
    myList.reverse();
    for(int val:myList)
    {
        cout<< val << endl;
    }
    return 0;
}