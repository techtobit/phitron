#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    string str;
    getline(cin, str);
    stringstream strs(str);
    string word;
    int flag = 0;
    while (strs>>word)
    {
        if(word == "Ratul"){
            flag = 1;
        }
    }
    if(flag !=0){
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    

    // int res = strs>>word.find("Rahat");

        // if (strs<<word.find("Rahat") !=-1)
        // {
        //     cout<<"YES"<<endl;
        // }
        //     else{
        // cout<<"NO"<<endl;
    
    // // int res = word.find("Rahat");
    // if(word.find("Rahat") !=-1){
    //     cout<<"YES"<<endl;
    //     // if(str.length()==5){
    //     // cout<<"YES"<<endl;
    //     // }
    //     // else{
    //     // cout<<"NO"<<endl;
    //     // }
    // }
    // else{
    //     cout<<"NO"<<endl;
    // };

    return 0;
}