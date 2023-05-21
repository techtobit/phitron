#include <stdio.h>
void fun(int i){
    if(i==6) return;
    //If statement use for brack from fun.
    //Avoid Infinite loop.
    printf("%d ",i);
    fun(i+1);
}
int main() {
    fun(1);
    return 0;
}