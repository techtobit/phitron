#include<stdio.h>
#include<string.h>
int main() {
    // int n;
    // scanf("%d",&n);
    // int ar[n+1];
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &ar[i]);
    // };

    // int pos, value;
    // scanf("%d %d",&pos,&value);
    // for (int i=n; i>=pos+1; i--)
    // {
    //     ar[i] = ar[i-1];
    // }
    // ar[pos]=value;
    // for (int i=0; i<n+1; i++)
    // {
    //     printf("%d ", ar[i]);
    // };


    // removed an element 
    // int n;
    // scanf("%d", &n);
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }
    // int pos;
    // scanf("%d", &pos);
    // for (int i = pos; i < n; i++)
    // {
    //     arr[i]=arr[i+1];
    // }

    // for (int i = 0; i < n-1; i++)
    // {
    //     printf("%d ", arr[i]);
    // }



    // revers array
    // int n;
    // scanf("%d", &n);
    // int ar[n];
    // for (int i = 0; i <n; i++)
    // {
    //     scanf("%d", &ar[i]);
    // }
    // int m=0, k=n-1;
    // while (m < k)
    // {
    //     int temp = ar[m];
    //     ar[m] = ar[k];
    //     ar[k] = temp ;
    //     m++;
    //     k--;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", ar[i]);
    // }
    

    // copy multiple array to new array
    // int n;
    // scanf("%d", &n);
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &a[i]);
    // }
    
    // int m;
    // scanf("%d", &m);
    // int b[m];
    // for (int i = 0; i < m; i++)
    // {
    //     scanf("%d",&b[i]);
    // }
    
    // int ans[n+m];
    // for (int i = 0; i < n; i++)
    // {
    //     ans[i] = a[i];
    // }
    // int i = n;
    // for (int j = 0; j < m; j++)
    // {
    //     ans[i]=b[j];
    //     i++;
    // }
    
    // for (int i = 0; i < n+m; i++)
    // {
    //     printf("%d ", ans[i]);
        
    // }
    
    

    // char s[5];
    // gets(s);
    // // int len = strlen(s);
    // printf("%s",s);


    // char s[100];
    // scanf("%s", &s);
    // int len = strlen(s);
    // int vowles = 0;
    // for (int i = 0; i < len; i++)
    // {
    //     scanf("%s", x);
    //     if (i == 'a')
    //     {
    //         printf("This is Vowle");
    //     }
        
    // }
    
    // printf("%d",len);

    // char s[1000];
    // scanf("%c", &s);
    // for (int i = 0; i < strlen(s); i++)
    // {
    //     printf("%d", i);
    // }

    // char s;
    // int chap =0, small =0;
    // while (scanf("%c", &s) !=EOF)
    // {
    //     if (s >= 'a' && s <= 'z' || s <= 'a' && s <='a'){

    //         if(s >= 'a' && s <= 'z'){
    //         printf("%d \n", s);
    //         small++;
    //     }
    //     else 
    //     {
    //         printf("%d \n", s);
    //         chap++;
            
    //     }
    //     }
    // }
    // printf("%d %d", chap, small);
    
    
    // int n, k;
    // scanf("%d %d", &n, &k); 
    // for (int i = 1; i < k; i++)
    // {
    //     for (int i = 1; i <=n; i++)
    //     {
    //         printf("%d ", i);
    //     }
    //     printf("%\n");
    // }

    // int n,x;
    // scanf("%d %d" , &n,&x);
    // int j;
    // scanf("%d ", &j);
    // int arr[x];
    // int count =0;
    // for (int i = 0; i <n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }
    // printf("%d",j);

    // for (int i = 0; i < n; i++)
    // {
    //     if(arr[i] == j){
    //         count++;
    //     }
    // }
    // if (count > 0)
    // {
    //     printf("%d", count);
    // }
    // else{
    //     printf("0");
    // }
    

    // int n, x, j, count = 0;
    // scanf("%d", &n);
    // int a[n];
    // for(int i = 0; i < n; i++) {
    //     scanf("%d", &a[i]);
    // }
    // scanf("%d", &x);
    // for(int i = 0; i < n; i++) {
    //     if(a[i] == x) {
    //         count++;
    //     }
    // }
    // printf("%d", count);


    char s[1001];
    int alph[26] = {0}; 
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; i++) {
        int value = s[i] - 'a';
        alph[value]++; 
    }
    for(int i = 0; i < 26; i++) {
        printf("%c - %d\n", 'a'+i, alph[i]); 
    }

    return 0;
}