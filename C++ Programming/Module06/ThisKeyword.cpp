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

    // you can diractly print value in a fun and print 
    // them by call the fun inside main fun
    void print_name()
    {
        cout<<"Name:"<<name<<" "<<"Age:"<<age<<endl;
    }

    //you can write a fun and return value to mail fun.
    int sum_of_marks()
    {
        return marks1+marks2;
    }
};

int main()
{
    Person Rakib("Md Rakibul", 20, 120, 90);
    Rakib.print_name();
    cout<<Rakib.sum_of_marks()<<endl;
    return 0;
}