// #include <stdio.h>

// int fun(char arr[], int i){

//     if(arr[i] == '\0') return 0;
//     int l = fun(arr, i+1);
//     return l+1;

// }
// int main() {
//     char a[6];
//     scanf("%s", &a);
//     int len = fun(a, 0);
//     printf("%d", len);
//     return 0;
// }

#include<stdio.h>
void fun()
{
    printf("fun\n");
    fun();
}
int main()
{
    fun();   
}