#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums, int x)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (x > nums[mid])
            low = mid + 1;
        else if (x == nums[mid])
            return mid;
        else
            high = mid - 1;
    }
    return low;
}
int main()
{
    int t;
    cin >> t;
    vector<int> nums;
    for (int i = 0; i < t; i++)
    {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    int x;
    cin >> x;

    int duplicate = findDuplicate(nums, x);

    if (duplicate > 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
