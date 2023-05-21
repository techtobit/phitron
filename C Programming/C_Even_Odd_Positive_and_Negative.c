#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int a;
    int even=0, odd=0, postive=0, negtive=0;
    for(int i =1; i <=n; i=i+1){
        scanf("%d",&a);
        if(a%2 == 0){
            even++;
        }
        else{
            odd++;
        }

        if(a > 0){
            postive++;
        }
        else if(a < 0){
            negtive++;
        }
    }
    printf("Even: %d\nOdd: %d\nPositive: %d\nNegative: %d", even, odd, postive, negtive);
    
    return 0;
}