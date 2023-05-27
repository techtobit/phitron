// #include <bits/stdc++.h>
// using namespace std;

// class person{
//     public:
//     int age;
//     float height;

//     person(int a, float h){
//         age=a;
//         height=h;
//     }
// };

// int main()
// {

//     person* rahim =new person(35, 5.9);
//     person* karim =new person(20, 5.2);

//     int personOne = rahim->age;
//     int personTwo = karim->age;
//     if(personOne > personTwo)
//     {
//         cout<<"PersonOne Is older and Age is"<<" "<<personOne<<endl;
//     }
//     else if(personOne > personOne){
//         cout<<"PersonTWo Is older and Age is"<<" "<<personTwo<<endl;
//     }
//     else{
//         cout<<"Both are same Age"<<personOne<<" "<<personTwo<<endl;
//     }

//     return 0;
// }

// #include <iostream>

// class MyClass {
// public:
//     int value;

//     MyClass(int val) : value(val) {}

//     void display() {
//         std::cout << "Value: " << value << std::endl;
//     }
// };

// MyClass& getStaticObject() {
//     static MyClass staticObj(42);
//     return staticObj;
// }

// int main() {
//     getStaticObject().display();
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int max_diff = 10;
    int min_val = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        if (val < min_val)
        {
            min_val = val;
        }
        else
        {
            max_diff = max(max_diff, val - min_val);
        }
    }

    cout << max_diff << endl;

    return 0;
}
