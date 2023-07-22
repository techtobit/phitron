#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<string> address;

    while (true)
    {
        string addressName;
        cin >> addressName;
        if (addressName == "end")
            break;
        address.push_back(addressName);
    }

    int Q;
    cin >> Q;

    auto current = address.begin();
    auto endAddress = address.end();

    for (int i = 0; i < Q; i++)
    {
        string command;
        cin >> command;

        if (command == "visit")
        {
            string addressToVisit;
            cin >> addressToVisit;

            bool found = false;
            for (auto it = address.begin(); it != address.end(); ++it)
            {
                if (*it == addressToVisit)
                {
                    current = it;
                    cout << *current << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "next")
        {
            if (++current != endAddress)
            {
                cout << *current << endl;
            }
            else
            {
                current--;
                cout << "Not Available" << endl;
            }
        }
        else if (command == "prev")
        {
            if (current != address.begin())
            {
                current--;
                cout << *current << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
