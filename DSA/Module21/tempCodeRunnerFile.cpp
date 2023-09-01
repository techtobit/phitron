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