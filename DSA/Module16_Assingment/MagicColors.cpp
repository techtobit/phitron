#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        stack<char> colors;
        int n;
        cin >> n;
        string color;
        cin >> color;
        for (int i = 0; i < color.size(); i++)
        {
            if (!colors.empty())
            {
                if(color[i] == colors.top())
                {
                    colors.pop();
                }
                else if(color[i]=='R' && colors.top()=='B' || color[i]=='B' && colors.top()=='R')
                {
                    colors.pop();
                    if(!colors.empty() && colors.top()=='P') colors.pop();
                    else colors.push('P');
                }
                else if(color[i] == colors.top())
                {
                    colors.pop();
                }
                else if(color[i]=='R' && colors.top()=='G' || color[i]=='G' && colors.top()=='R')
                {
                    colors.pop();
                    if(!colors.empty() && colors.top()=='Y') colors.pop();
                    else colors.push('Y');
                }
                else if(color[i] == colors.top())
                {
                    colors.pop();
                }
                else if(color[i]=='B' && colors.top()=='G' || color[i]=='G' && colors.top()=='B')
                {
                    colors.pop();
                    if(!colors.empty() && colors.top()=='C') colors.pop();
                    else colors.push('C');
                }
                

                else
                {
                    colors.push(color[i]);
                }
            }
            else
            {
                colors.push(color[i]);
            }
        }

        // while (!colors.empty())
        // {
        //     cout << colors.top();
        //     colors.pop();
        // }
        // cout << endl;
        stack<char> colorsNew;
        while (!colors.empty())
        {
            colorsNew.push(colors.top());
            colors.pop();
        }

        while (!colorsNew.empty())
        {
            cout << colorsNew.top();
            colorsNew.pop();
        }
        cout<<endl;
    }
    return 0;
}