#include <stdio.h>
#include <string.h>

// void fun(char arr[]){
//     int size = strlen(arr);
//     printf("%d ", size);

// }
// int main() {
//     char arr[15] = "Hello";
//     fun(arr);
//     return 0;
// }

// int coutnBeforZero(int arr[], int size){
//     int count =0;
//     for (int i = 0; i < size; i++)
//     {
//         if(arr[i] == 0){
//             // printf("%d num index - %d",i, arr[i]);
//             break;
//         }
//         count++;
//     }
//     printf("%d", count);
//     return 0;
    
// }
// int main()
// {
//     int arr[50], size;
//     scanf("%d", &size);
//     for (int i = 0; i < size; i++)
//     {
//         scanf("%d", &arr[i]);
//         // printf("%d\n", arr[i]);
//     }
//     // printf("%d", size);
//     coutnBeforZero(arr, size);
//     return 0;
// }



// int is_palindrome(char* str) {
//     int i = 0;
//     int j = strlen(str) - 1;
    
//     while (i < j) {
//         if (str[i] != str[j]) {
//             return 0;
//         }
//         i++;
//         j--;
//     }
    
//     return 1;
// }

// int main() {
//     char str[11];
//     int result;
    
//     printf("palindrome");
//     scanf("%s", str);
    
//     result = is_palindrome(str);
    
//     if (result == 1) {
//         printf("Palindrome\n");
//     } else {
//         printf("Not Palindrome\n");
//     }
    
//     return 0;
// }


int is_palindrome(char *str){

    char str2[11]="palindrome";
    if (strcmp(str, str2) == 0) {
        return 1;
    }else{
        return 0;
    } 
    return 1;
}
int main(){
    char str[11];
    scanf("%s", str);
    int result = is_palindrome(str); 

    if (result == 1) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }
    
    return 0;
}