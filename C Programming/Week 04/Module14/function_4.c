#include <stdio.h>

void sub(void){
    //can't pass and recived any value inside sub fun
    int m= 9, k = 5;
    int sub = m - k;
    printf("%d", sub);
    return;
}
int main() {
    sub();
    return 0;
}
