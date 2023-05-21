#include <stdio.h>

void sub(int a, int b){
    //void fun can pass vlue but can recive
    //for that we take input from main fun
    //and recived it here as a perametars.
    int sum = a + b;
    printf("%d", sum);
    return;
    //don't need to return anything because
    //it's not passing anything.
}
int main() {
    int a=5, b=4;
    sub(a, b);
    //pusing varaible / value 
    return 0;
}