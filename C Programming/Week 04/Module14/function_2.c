#include <stdio.h>

int sub(){
    //if you use sub(void) fun will give
    //error is you send any value from mainFun.
    int a, b;
    scanf("%d %d", &a, &b);
    int sub = a - b;
    return sub;
}
int main() {
    int s = sub(); 
    //if you pass any value inside sub(110)
    // it's will not task a a parametars
    printf("%d", s);
    return 0;
}