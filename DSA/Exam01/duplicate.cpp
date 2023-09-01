#include<bits/stdc++.h>
using namespace std;


void fequencyArray(int a[], int size){
    
    bool flag = false;
    for (size_t i = 0; i < size; i++){
        for (size_t j = i+1; j < size; j++)
        {
            if(a[i]==a[j]){
                flag = true;
                break;
            }
        }
    }
    if(flag == true){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
        

    
};

int main()
{   int n; 
    cin>>n;
    int a[n];
    int size = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin>>a[i];
        size = sizeof(a) / sizeof(a[i]);
    };

    fequencyArray(a, size);
    
    return 0;
}