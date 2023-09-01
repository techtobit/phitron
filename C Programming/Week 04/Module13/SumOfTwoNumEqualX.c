#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int x;
    scanf("%d", &x);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // printf("%d %d \n", a[i], a[j]);
            if (a[i] + a[j] == x)
            {
                // int sum = a[i] + a[j];
                // printf("%d\n", sum);
                flag = 1;
            }
            // else 
            // {
            //     a[n]++;
            // }
        }
    }
    if (flag == 0)
    {
        printf("NO\n");
    }
    else
    {
        printf("Yes\n");
    }

    // int b[n];
    // for (int j = i; j < n - 1; j++)
    // {
    //     scanf("%d", &b[j]);
    //     // if (a[i]+b[j] == 18)
    //     // {
    //     //     int sum =a[i]+b[j];
    //     //     printf("%d\n" , sum);
    //     // }
    //     // else{
    //     //     b[n]++;
    //     // }
    //     if (a[i] + b[j] != 17)
    //     {
    //         b[n]++;
    //     }
    //     else if (a[i] + b[j] == 17)
    //     {
    //         int sum = a[i] + b[j];
    //         printf("%d\n", sum);
    //     }
    // }

    return 0;
}