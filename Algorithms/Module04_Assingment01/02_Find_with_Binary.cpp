#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *right;
    Node *left;

    Node(int val) {
        this->val = val;
        this->right = nullptr;
        this->left = nullptr;
    }
};

Node *input_Binary_Tree() {
    int val;
    cin >> val;
    Node *root = nullptr;
    if (val != -1)
        root = new Node(val);
    else
        return nullptr;

    queue<Node *> myQueue;
    myQueue.push(root);

    while (!myQueue.empty()) {
        Node *parentNode = myQueue.front();
        myQueue.pop();

        int l, r;
        cin >> l >> r;
        if (l != -1) {
            parentNode->left = new Node(l);
            myQueue.push(parentNode->left);
        }
        if (r != -1) {
            parentNode->right = new Node(r);
            myQueue.push(parentNode->right);
        }
    }
    return root;
}

bool search_node(Node *root, int x) {
    while (root != nullptr) {
        if (root->val == x)
            return true;
        else if (x < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int main() {
    Node *root = input_Binary_Tree();
    if (search_node(root, 6))
        cout << "YES, Found" << endl;
    else
        cout << "NO, Not Found" << endl;
    return 0;
}
