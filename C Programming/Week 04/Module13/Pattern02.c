#include <stdio.h>
int main() {
    int n, k=1;
    scanf("%d", &n);
    int s=n-1;
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < s; i++)
        {
            printf(" ");
        
        }
        s--;

        for (int i = 0; i < k; i++)
        {
            printf("*");
        
        }
        k +=2;
        
        printf("\n");
    }
    
    return 0;
}