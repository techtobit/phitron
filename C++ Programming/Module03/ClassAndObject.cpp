#include <bits/stdc++.h>
using namespace std;

class student{
    public:
    char name[100];
    int roll;
    int cls;
    char section;
};

int main()
{
    student rahim;
    rahim.roll = 10;
    rahim.cls= 9;
    rahim.section='A';
    char nm[100] = "Rahim";
    strcpy(rahim.name, nm);

    cout<<rahim.name;
    return 0;
}