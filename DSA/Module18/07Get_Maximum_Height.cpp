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
        // 01 - bere kore ante hobe
        Node *perent = myQueue.front();
        myQueue.pop();

        // 02 - jabotio kaj korbo
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

        perent->left = myLeft;
        perent->right = myRight;

        // 03 Print Korte Hobe;
        if (perent->left)
            myQueue.push(perent->left);
        if (perent->right)
            myQueue.push(perent->right);
    }
    return root;
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
    cout << countMaxHeight(root) << endl;
    return 0;
}