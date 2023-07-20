#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

int main()
{   
    list<int>LinkedList;
    int val;
    while (true)
    {
        cin>>val;
        if(val == -1) break;
        LinkedList.push_back(val);
    }
    
    LinkedList.sort();
    LinkedList.unique();

    for(int val:LinkedList){
        cout<< val << " ";
    }
    cout<< endl;
    return 0;
}