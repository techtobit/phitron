#include <stdio.h>
int main()
{
    int N, i=0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        if(i%5==0){
            printf("Yes\n");
        }
        else
        {printf("No\n");}
    }
    
    // int n;
    // scanf("%d", &n);
    // int div3 = n /3;
    // int div7 = n%7;



    // int rem3 = div3 % 
    // printf("%d %d", div3, div7);
    // for (int i = 0; i < n; i++)
    // {
    //     if(i/7 ==0 && i%7 == 0 ){
    //         printf("%d\n", i);
    //     }
    // }
    
    

    // int n;
    // printf("Enter a non-negative integer: ");
    // scanf("%d", &n);

    // if (n % 3 == 0)
    //     printf("YES");
    // else
    //     printf("NO");

    // return 0;
    
    return 0;
}