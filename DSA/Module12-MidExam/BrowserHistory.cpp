#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<string> address;
    // address.push_back("facebook google phitron youtube twitter");

    while (true)
    {
        string addressName;
        cin >> addressName;
        if (addressName == "end")
            break;
        address.push_back(addressName);
    }

    // for(string val:address)
    // {
    //     cout<< val <<endl;
    // }

    int cl;
    cin >> cl;
    // list<string> commandLists;
    for (int i = 1; i < cl; i++)
    {
        string commands;
        cin >> commands;
        // getline(cin, commands);
        // commandLists.push_back(commands);
        auto it = find(address.begin(), address.end(), commands);
        if (*it == commands)
        {
            cout << *it << endl;
        }
        else cout << "Not Available" << endl;

        // for (string val : commands)
        // {
        //     cout << val << endl;
        // }
    }

    // for(string val : commandLists)
    // {
    //     cout<< val << endl;
    // }

    // auto it = find(address.begin(), address.end(), commandLists);
    // if(*it == commandLists)
    // {
    //     cout<< *it <<endl;
    // }
    // else cout<< "Not Available" << endl;

    return 0;
}