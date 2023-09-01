#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *right;
    Node *left;

    Node(int val)
    {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};
Node *inputBinaryTree()
{
    int val;
    cin >> val;

    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> myQueue;
    if (root)
        myQueue.push(root);

    while (!myQueue.empty())
    {
        Node *perent = myQueue.front();
        myQueue.pop();

        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;

        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        perent->right = myRight;
        perent->left = myLeft;

        if (perent->left)
            myQueue.push(perent->left);
        if (perent->right)
            myQueue.push(perent->right);
    }

    return root;
}

vector<int> v;
void levelOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "No Root Avaliable";
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        Node *f = q.front();
        q.pop();
        // vector<int>v;
        v.push_back(f->val);

        if (f->right)
            q.push(f->right);
        if (f->left)
            q.push(f->left);
    }
};

int main()
{
    Node *root = inputBinaryTree();
    levelOrder(root);
    reverse(v.begin(), v.end());
    for (int val : v)
    {
        cout << val << " ";
    }
    return 0;
}