#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int val;
    Node* right;
    Node* left;

    Node(int val)
    {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};
Node* inputBinaryTree()
{
    int val;
    cin>>val;

    Node* root;
    if(val == -1) root = NULL;
    else root = new Node(val);

    queue<Node*> myQueue;
    if(root) myQueue.push(root);

    while (!myQueue.empty())
    {
        // 01 - Queue teke ber kore ana;
        Node* perent = myQueue.front();
        myQueue.pop();

        // 02 - Rest of job
        int l, r;
        cin>>l>>r;
        Node* myLeft;
        Node* myRight;

        if(l == -1) myLeft = NULL;
        else myLeft = new Node(l);

        if(r == -1) myRight = NULL;
        else myRight = new Node(r);

        perent->left = myLeft;
        perent->right = myRight;

        // 03 - print 
        if(perent->left) myQueue.push(perent->left);
        if(perent->right) myQueue.push(perent->right);
    }
    
    return root;
}

int sum = 0;

void levelOrder(Node* root)
{
    if(root == NULL)
    {
        cout<<"No Root Avaliable";
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // 01- bere kore ana nodes form stack
        Node *f = q.front();
        q.pop();

        // 02 - Jabotio kaj kora
        // cout << f->val << " ";
        sum += f->val;

        // 03 - root er childern golo ke raka
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
};


int main()
{
    Node* root =  inputBinaryTree();
    levelOrder(root);
    return 0;
}