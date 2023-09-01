#include <stdio.h>

// int main() {
//   int t, s, a, b, c, missing;

//   scanf("%d", &t);

//   while (t--) {
//     scanf("%d %d %d %d", &s, &a, &b, &c);

//     missing = s - a - b - c;

//     printf("%d\n", missing);
//   }

//   return 0;
// }




#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n -i; j++)
        {
            printf(" ");
        }
        
        for (int j = 0; j < 2*i -1; j++)
        {
            if (i%2 == 0)
            {
                printf("*");
            }
            else{
                printf("^");
            }
            
        }
        printf("\n");
        
        
    }
    
    

    return 0;
}









