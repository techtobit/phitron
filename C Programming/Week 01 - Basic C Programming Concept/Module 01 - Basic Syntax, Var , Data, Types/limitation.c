#include<stdio.h>

int main()
{
    // //interger limitation 10^9 / 10^-9
    // int a = 10000000000;
    // // 8bit -> 64byte = 10^18 / 10^-18
    // long long int b = 10000000000;
    // printf("%lld", b);
    // return 0;

    // float a=2005.55686786545;
    double a=22.55686786545642;
    // printf("%f", a);
    printf("%0.15lf", a);
    return 0;
}