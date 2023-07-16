#include<bits/stdc++.h>
using namespace std;
int main()
{   
    list<int>myList ={10, 20, 30};
    //remove all value from list
    // myList.clear();
    myList.resize(2);
    //after 2nd value removed all others
    myList.resize(5,100);
    // will create total list of 100 five times 
    for(int val:myList)
    {
        cout<< val <<endl;
    }
    return 0;
}