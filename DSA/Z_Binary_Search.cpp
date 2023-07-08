#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n, q;
    cin>>n>>q;
    int a[n];
    for (size_t i = 0; i < n; i++)
    //time complixity O(n)
    {
        cin>>a[i];
    }
    

    while (q--)
    //time complixity O(q)
    {
        int x;
        cin>>x;
        bool flag = false;
        for (size_t i = 0; i < n; i++)
        //time complixity O(n)
        {   
            if(a[i] == x){
                flag = true;
                break;
            }
        }
        
        if(flag == true){
            cout<<"found"<<endl;
        }else cout<<"not found"<<endl;
    }
    
    
    //time complixity total= O(n) + O(q)* O(n)
                // O(qn)=> 10^5 * 10^5 = 10^10;

    return 0;
}