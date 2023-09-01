#include <stdio.h>
#include <string.h>
int main() {
    char a[100],b[100];
    scanf("%s %s", a, b);
    int i =0;

    //In build function & short hend
    int v = strcmp(a,b);
    printf("%d\n", v);
    if(v < 0){
        printf("A is Small\n");
    }
    else if(v > 0){
        printf("B is Small\n");
    }
    else{
        printf("Both are Equla");
    }

    //How its actuly works
    
    // while (1)
    // {
    //     if (a[i]=='\0' && b[i]=='\0')
    //     {
    //         printf("Same\n");
    //         break;
    //     }
    //     else if(a[i] == '\0'){
    //         printf("A Small\n");
    //         break;
    //     }
    //     else if(b[i] == '\0'){
    //         printf("B small\n");
    //         break;
    //     }
        
    //     if(a[i]==b[i]){
    //         printf("Both are same\n");
    //         i++;
    //     }
    //     else if(a[i] > b[i]){
    //         printf("B is small\n");
    //         break;
    //     }
    //     else{
    //         printf("A is small\n");
    //         break;
    //     }
    // }
    
    return 0;
}