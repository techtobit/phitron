#include <stdio.h>
#include <string.h>
int main() {

    int alph[26] = {0};
    char ch;
    while (scanf("%c",&ch) !=EOF)
    {
        int value = ch- 'a';
        alph[value]++;
    }   
    for (int i = 0; i < 26; i++)
    {
        if (alph[i] > 0)
        {
            printf("%c : %d\n", i+'a', alph[i]);
        }
    }
    return 0;
}