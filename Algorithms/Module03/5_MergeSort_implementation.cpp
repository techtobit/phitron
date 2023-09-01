#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int nums[N];

void merge(int l, int r, int mid)
{
    int left_size = mid - l +1;
    int right_size = r - mid +1;

    int L[left_size];
    int R[right_size];

    for (int i = 0; i < left_size; i++)
        L[i] = nums[l + i];
    for (int i = 0; i < right_size; i++)
        R[i] = nums[mid + 1 + i];

    L[left_size] = INT_MAX;
    R[right_size] = INT_MAX;

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] <= R[rp])
        {
            nums[i] = L[lp];
            lp++;
        }
        else
        {
            nums[i] = R[rp];
            rp++;
        }
    }
}


void mergeSort(int l, int r)
{
    if (l == r)
        return;

    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    merge(l, r, mid);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
