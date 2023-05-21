#include <stdio.h>
void fun(int i){
    if(i==0) return;
    //If statement use for brack from fun.
    //Avoid Infinite loop.
    printf("%d ",i);
    fun(i-1);
}
int main() {
    fun(5);
    return 0;
}