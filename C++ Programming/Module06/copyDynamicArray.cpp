#include <bits/stdc++.h>
using namespace std;

class Person
{
    public :
    string name;
    int age, marks1, marks2;

    Person(string name, int age, int marks1, int marks2){
        this->name = name;
        this->age = age;
        this->marks1 = marks1;
        this->marks2 = marks2;
    }


};

int main()
{
    Person* Rakib = new Person("Md Rakibul", 20, 70, 90);
    Person* Sakib = new Person("Sakibul", 22, 85, 92);
    // way 1
    // Rakib = Sakib;

    // Way 2
    // Rakib->name = Sakib->name;
    // Rakib->age = Sakib->age;

    // way 3
    *Rakib = *Sakib;
    delete Sakib;
    cout<<Rakib->name<<" "<<Rakib->age<<endl;
}