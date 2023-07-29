#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     string x, y;
//     while (getline(cin, x),  getline(cin, y))
//     {
//         sort(x.begin(), x.end());
//         sort(y.begin(), y.end());
//         y.erase(y.find_last_not_of(' ') + 1);
//         cout << x << endl;
//         cout << y << endl;
//     }

//     return 0;
// }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (size_t i = 0; i < n; i++)
        {
            cin>>a[i];
            // cout<<a[i]<<" ";
        }
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i+1; j < n; j++)
            {
                // if(a[i] > a[j])
                // {
                //     // swap(a[i], a[j]);
                //     cout<<a[i]<<" "<<a[j];
                // }
                

            }
            
        }
        int count = 0;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i+1; j < n; j++)
            {
                if(a[i] == a[j])
                {
                    count++;
                }

            }
            
        }

        cout<<count<<endl;
        
    }
}