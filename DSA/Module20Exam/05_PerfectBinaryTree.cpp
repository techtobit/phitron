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

void nodeLevel(Node *root, int level)
{
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> current = q.front();
        q.pop();

        Node *node = current.first;
        int nodeLevel = current.second;

        if (nodeLevel == level)
        {
            v.push_back(node->val);
        }

        if (node->left)
        {
            q.push({node->left, nodeLevel + 1});
        }
        if (node->right)
        {
            q.push({node->right, nodeLevel + 1});
        }
    }
}

int count(Node *root)
{
    if (root == NULL)
        return 0;

    int l = count(root->left);
    int r = count(root->right);
    return l + r + 1;
}

int countMaxHeight(Node *root)
{
    if (root == NULL)
        return 0;

    int l = countMaxHeight(root->left);
    int r = countMaxHeight(root->right);
    return max(l, r) + 1;
}

int main()
{
    Node *root = inputBinaryTree();
    int mycount = count(root);
    cout<<mycount<<endl;
    int myHeight = countMaxHeight(root);
    cout<<myHeight<<endl;
    int totalNode = pow(2, myHeight)-1;
    cout<<totalNode<<endl; 
    if (totalNode == mycount)
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

        return 0;
}