void merge(int l, int r, int mid)
{
    int left_size=mid-l +1;
    int right_size=r-mid;;

    int L[left_size +1];
    int R[right_size +1];

    for(int i=0; i<left_size; i++)
    {
        L[i] = nums[l+1];
    }
    for (int i = 0; i < right_size; i++)
    {
        R[i] = nums[mid+1+i];
    }

    L[left_size] = INT_MIN;
    R[right_size] = INT_MIN;

    int lp=0, rp=0;

    for(int i=l; i<=r; i++)
    {
        if(L[lp] >= R[rp])
        {
            nums[i] = L[lp];
            lp++;
        }
        else
        {
            nums[i]=R[rp];
            rp++;
        }
    }
    
}