Node *insertBST(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->val)
        root->left = insertBST(root->left, val);
    else if (val > root->val)
        root->right = insertBST(root->right, val);

    return root;
}