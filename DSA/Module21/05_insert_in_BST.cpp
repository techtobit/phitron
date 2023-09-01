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

    queue<Node *> myQueue;
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

void insert_in_BST(Node *&root, int insertVal)
{
    if (root == NULL)
    {
        root = new Node(insertVal);
        return;
    }

    if (insertVal < root->val)
    {
        if (root->left == NULL)
        {
            root->left = new Node(insertVal);
        }
        else
            insert_in_BST(root->left, insertVal);
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new Node(insertVal);
        }
        else
            insert_in_BST(root->right, insertVal);
    }

}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->val << " ";
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}
int main()
{
    // input 
    // 20 10 30 -1 15 25 35 -1 -1 -1 -1 -1 -1
    Node *root = input_Binary_Tree();
    // int insertVal; cin>>insertVal;
    insert_in_BST(root, 13);
    insert_in_BST(root, 40);
    levelOrder(root);
    return 0;
}