#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int b;
    int bigNum=0;
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &b);
        if(b > bigNum){
            bigNum =b;
        }
    }
    printf("%d", bigNum);
    
    return 0;
}