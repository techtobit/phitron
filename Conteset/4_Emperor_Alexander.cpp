#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;


    while (t--)
    {
        int n;
        cin >> n;

        vector<int> h(n);
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }

        int left = 0, right = n - 1;
        int maxArea = 0;
        int maxLeft = 0, maxRight = 0;

        while (left < right)
        {
            int area = min(h[left], h[right]) * (right - left);
            if (area > maxArea)
            {
                maxArea = area;
                maxLeft = left;
                maxRight = right;
            }

            if (h[left] < h[right])
            {
                left++;
            }
            else if (h[left] > h[right])
            {
                right--;
            }
            else
            {
                if (left < right)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        cout << maxLeft << " " << maxRight << endl; // Print the indices of the maximum area
    }

    return 0;
}