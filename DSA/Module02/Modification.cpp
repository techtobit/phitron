#include<bits/stdc++.h>
using namespace std;

int main()
{   
    // Method - singel Value input 
    // vector<int> v ={1, 2, 3, 4, 5};
    // // insert - a modifire fun 
    // // v.begin - means start from the frist index 
    // // v.begin()+2 - 2 is a pointer means 2no index 
    // // 10 - 2no index replace by 10 
    // v.insert(v.begin()+2, 10);
    // //shortcut for loop
    // for(int x:v){
    //     cout<<x<< " ";
    // }

    // Method 02 - Insert another Vector 
    vector<int> v ={1, 2, 3, 4, 5};
    // vector<int> v2 ={100, 200, 300, 400};
    // v.insert(v.begin()+2, v2.begin(), v2.end() );
    

    //Erese Data from Vector
    v.erase(v.begin()+1);

    //remove multiple
    v.erase(v.begin()+1, v.begin()+3);
    // v.erase(v.begin()+1, v.end()-1);
    
    //shortcut for loop
    for(int x:v){
        cout<<x<< " ";
    }
    
    return 0;
}