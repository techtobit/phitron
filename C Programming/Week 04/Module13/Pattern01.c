#include <stdio.h>
int main() {
    int n, k=1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < k; i++)
        {
            printf("*");
        
        }
        k++;
        
        printf("\n");
    }
    
    return 0;
}