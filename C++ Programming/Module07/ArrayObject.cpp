#include <bits/stdc++.h>
using namespace std;

class Student
{
    public:
    string name;
    int age;
    int marks;
};

int main()
{
    
    Student a[3];
    for (int i = 0; i < 3; i++)
    {
        getline(cin,a[i].name);
        cin>>a[i].age>>a[i].marks;
        cin.ignore();
    }

    for (int i = 0; i < 3; i++)
    {
        cout<<a[i].name<< " "<< a[i].age<< " "
        << a[i].marks<<endl;
    }
    
    
    return 0;
}