#include<bits/stdc++.h>
using namespace std;

// void mergeSortArrays(int arr1[], int arr2[], int size1, int size2, int mergeArr[])
// {
//     int i=0;
//     int j=0;
//     int k=0;

//     while (i<size1 && j<size2)
//     {
//         if(arr1[i] <= arr2[j])
//         {
//             mergeArr[k]=arr1[i];
//             i++;
//         }
//         else
//         {
//             mergeArr[k]=arr2[j];
//             j++;
//         }
//         k++;
//     }

//     while (i<size1)
//     {
//         mergeArr[k]=arr1[i];
//         i++;
//         k++;
//     }

//     while (j<size2)
//     {
//         mergeArr[k]=arr2[j];
//         j++;
//         k++;                         
//     }
    
    
    
// };

// int main()
// {   
//     int arr1[] ={1, 3, 5, 7, 9};
//     int size1= sizeof(arr1)/ sizeof(arr1[0]);
    
//     int arr2[] ={2, 4, 6, 8, 10};
//     int size2=sizeof(arr2)/ sizeof(arr2[0]);

//     int mergeSize = size1+size2;
//     int mergeArr[mergeSize];

//     mergeSortArrays(arr1, arr2, size1, size2, mergeArr);


//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 7;
int arr1[N];
int arr2[N];
int nums[N];

void merge(int l, int r, int mid)
{
    int left_size = mid - l + 1;
    int right_size = r - mid;

    int L[left_size + 1];
    int R[right_size + 1];

    for (int i= 0; i < left_size; i++)
        L[i] = nums[l + i];
    for (int i = 0; i < right_size; i++)
        R[i] = nums[mid + 1 + i];

    L[left_size] = INT_MIN;
    R[right_size] = INT_MIN;

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] >= R[rp])
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
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    merge(l, r, mid);
}

int main()
{
    int n1;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    int mergeSize = n1 + n2;

    for (int i = 0; i < mergeSize; i++)
    {
        if (i < n1)
            nums[i] = arr1[i];
        else
            nums[i] = arr2[i - n1];
    }

    mergeSort(0, mergeSize - 1);


    for (int i = 0; i <mergeSize; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}





