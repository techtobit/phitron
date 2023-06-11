#include <bits/stdc++.h>
using namespace std;

class Student
{
    public:
    string name;
    int cls;
    string section;
    int id, mathMarks, engMarks;
};

bool cmp(Student a, Student b)
{
    return a.mathMarks+a.engMarks > b.mathMarks+b.engMarks
    || a.mathMarks+a.engMarks == b.mathMarks+b.engMarks && a.id < b.id;
}

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    Student x[n];
    for (int i = 0; i < n; i++)
    {
        cin>>x[i].name>>x[i].cls>>x[i].section>>x[i].id>>x[i].mathMarks>>x[i].engMarks;
        cin.ignore();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            sort(x, x+n, cmp);
            // swap(x[i].cls, x[j].cls);
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        cout<<x[i].name<<" "<<x[i].cls<<" "<<
        x[i].section<<" "<<x[i].id<<" "<<
        x[i].mathMarks<<" "<<x[i].engMarks<<endl;
    }
    return 0;
}