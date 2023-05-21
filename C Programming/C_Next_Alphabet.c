#include <stdio.h>
int main() {
    char c;
    scanf("%c", &c);
    if(c >= 97 && c < 122 )
    {
        printf("%c", c + 1);
    }
    else if ( c == 122){
        c -= 25;
        printf("%c", c);
    }  
    return 0;
}