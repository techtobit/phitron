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

Node *input_Binary_Tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node*> myQueue;
    if (root)
        myQueue.push(root);

    while (!myQueue.empty())
    {
        Node *perentNode = myQueue.front();
        myQueue.pop();

        int l, r;
        cin >> l >> r;
        Node *inputLeft;
        Node *inputRight;
        if (l == -1)
            inputLeft = NULL;
        else
            inputLeft = new Node(l);
        if (r == -1)
            inputRight = NULL;
        else
        inputRight = new Node(r);
        perentNode->left = inputLeft;
        perentNode->right = inputRight;

        if (perentNode->left)
            myQueue.push(perentNode->left);
        if (perentNode->right)
            myQueue.push(perentNode->right);
    }
    return root;
};

bool search_node(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->val == x)
        return true;
    if (x < root->val)
        return search_node(root->left, x);
    else
        return search_node(root->right, x);
};

int main()
{
    Node *root = input_Binary_Tree();
    if (search_node(root, 6))
        cout << "YES, Found" << endl;
    else
        cout << "NO, Not Found" << endl;
    return 0;
}