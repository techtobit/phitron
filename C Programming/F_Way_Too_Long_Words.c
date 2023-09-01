#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char ch [102];
        scanf("%s", ch);
        int size = strlen(ch);
        if(size > 10){
            printf("%c%d%c\n", ch[0],size-2,ch[size-1]);
        }
        else{
            printf("%s\n",ch);
        }
    }
    

    return 0;
}