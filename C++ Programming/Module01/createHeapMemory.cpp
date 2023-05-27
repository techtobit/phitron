#include <bits/stdc++.h>
using namespace std;

int main() {
    int *a = new int [5];
    for (int i = 0; i < 5; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    return 0;
}


Dynamic memory allocation is necessary when we need to allocate and deallocate memory at runtime. It is useful in situations such as:


#include <iostream>

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size]; 

    delete[] arr; 

    return 0;
}