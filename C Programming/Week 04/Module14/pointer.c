#include <stdio.h>
#include <math.h>
// int main() {
//     int x = 10;
//     printf("%p\n", &x);
//     int *p = &x;
//     printf("%p", p);
//     return 0;
// }

    int main()
    {
        int s = 10;
        int *p = &s;
        // printf("%p\n", &s);
        *p = 50;
        printf("%p\n", &p);
        printf("%d\n", *p);
        return 0;
    } 
