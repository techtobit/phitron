#include <bits/stdc++.h>
using namespace std;

int main()
{
    // -- basic -- //

    // vector<int> v = {50, 40, 45, 30, 35, 42, 32, 25, 20, 10};
    // int x;
    // cin >> x;
    // v.push_back(x);
    // int cur_idx = v.size() - 1;
    // // cout<<cur_idx<<endl;

    // while (cur_idx != 0)
    // {
    //     int parent_idx = (cur_idx - 1) / 2;
    //     // cout << parent_idx << endl;
    //     if (v[parent_idx < cur_idx])
    //         swap(v[parent_idx], v[cur_idx]);
    //     else
    //         break;
    //     cur_idx = parent_idx;
    // }

    // for(int val :v)
    // {
    //     cout<< val<< " ";
    // }

    // -- take value input -- //
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        int cur_idx = v.size() - 1;
        while (cur_idx != 0)
        {
            int parent_idx = (cur_idx - 1) / 2;
            if (v[parent_idx < cur_idx]) //max heap
            // if (v[parent_idx > cur_idx]) //min heap
                swap(v[parent_idx], v[cur_idx]);
            else
                break;
            cur_idx = parent_idx;
        }
    }

    for (int val : v)
    {
        cout << val << " ";
    }
    return 0;
}