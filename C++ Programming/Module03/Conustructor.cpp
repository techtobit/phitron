#include <bits/stdc++.h>
using namespace std;

class Person{
    public:
    char name[100];
    float height;
    int age;

    Person(float f, int a, char* nm){
        height =f;
        age = a;
        strcpy(name, nm);
    }
};



int main()
{
    Person rahim(2.4, 9, "Ashraf");
    cout<<rahim.name<<endl;
    cout<<rahim.age;

    return 0;
}