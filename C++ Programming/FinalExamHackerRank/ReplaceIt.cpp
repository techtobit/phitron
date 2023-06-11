// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string str = "PogrammingPhitronHero";
//     while (str.find("Phitron") !=-1)
//     {
//         str.replace(str.find("Phitron", 7, " "));
//     }
    
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    // cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string a,b;
        cin>>a>>b;
        // cin.ignore()
        for (int j=0; j<a.size(); j++) 
        {
            if (a[j]==b[0]) 
            {
            int k=1;

            while (j+k< a.size() && a[j+k]== b[k]) 
            {
                k++;
            }

            if (k==b.size()) {
                a.replace(j, k, "$");
            }
            }
        }
    cout<<a<<endl;
    }
    
    // for (int i = 0; i < n; i++)
    // {
    //     int res = str[i].find("g");
    //     // str[i].replace(res, 1, "$");
    //     // res = str[i].find("s");
    //     // cout<<str[i]<<endl;
    //     while (res != -1)
    //     {
    //     str[i].replace(res, 1, "$");
    //     res = str[i].find("g");
    //     }
    //     cout << str[i] << endl;
    // }
    return 0;
}




