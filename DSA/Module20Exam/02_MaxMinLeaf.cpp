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
        Node *perentNode = myQueue.front();
        myQueue.pop();

        int l, r;
        cin >> l >> r;
        Node *left;
        Node *right;
        if (l == -1)
            root = NULL;
        else
            left = new Node(l);

        if (r == -1)
            root = NULL;
        else
            left = new Node(r);

        perentNode->left = left;
        perentNode->right = right;

        if (perentNode->left)
            myQueue.push(perentNode->left);
        if (perentNode->right)
            myQueue.push(perentNode->right);
    }
    return root;
}

int minNode = INT_MAX;
int maxNode = INT_MIN;

int getMinNode(Node *root)
{
    if (root == NULL)
        return INT_MAX;
    if (root->left == NULL && root->right == NULL)
        return root->val;
    int left = getMinNode(root->left);
    int right = getMinNode(root->right);
    return min(left, right);
}

int getMaxNode(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    if (root->left == NULL && root->right == NULL)
        return root->val;
    int left = getMaxNode(root->left);   
    int right = getMaxNode(root->right);
    return max(left, right);
}
int main()
{
    Node *root = inputBinaryTree();
    int minNode = getMinNode(root);
    int maxNode = getMaxNode(root);
    cout << minNode <<" "<< maxNode;
    return 0;
}