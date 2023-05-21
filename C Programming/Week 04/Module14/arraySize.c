#include <stdio.h>

void fun(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    
}
int main() {
    int arr[5] = {20, 30, 50, 60, 10};
    fun(arr, 5);
    return 0;
}