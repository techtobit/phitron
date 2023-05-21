#include <stdio.h>

// how to write a function
// data_type functionName (parameters){

//     code 
//     return Variable
// }

int sum( int x, int y){
    int sum = x+y;
    return sum;
}
int main() {
    int m,n;
    scanf("%d %d",&m, &n);

    int result = sum(m, n);
    printf("%d", result);
    return 0;
}