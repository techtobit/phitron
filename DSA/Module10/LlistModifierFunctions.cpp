#include<bits/stdc++.h>
using namespace std;
int main()
{   
    list<int>myList = {10, 20, 20, 40};
    // list<int>newList;
    // newList = myList;
    // newList.assign(myList.begin(), myList.end());

    //intert at tail
    // myList.push_back(100);

    // insert at head 
    // myList.push_front(90);


    //deleted from tail
    // myList.pop_back();
    // myList.pop_back();

    //deleted from haed;
    // myList.pop_front();

    // instert at any positions 
    // myList.insert(next(myList.begin(), 2),100);

    //deleted from any postiton.
    // myList.erase(next(myList.begin(), 2));

    //insert from any vector/arrray/list.
    // vector<int>v = {50, 60, 70};
    //full vector will insert at positions 2.
    // myList.insert(next(myList.begin(), 2), v.begin(), v.end());


    //deleted multiple value from x to y;
    // myList.erase(next(myList.begin(), 1), next(myList.begin(), 3));

    //replace multiple x by multiple y;
    // replace(myList.begin(), myList.end(), 20, 100);
    // for(int val:myList)
    // {
    //     cout<< val <<endl;
    // }

    // find any value from list 
    auto it = find(myList.begin(), myList.end(), 20);
    cout<< *it <<endl;
    return 0;
}