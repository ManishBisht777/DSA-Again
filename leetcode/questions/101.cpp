bool issymmetrichelp(TreeNode *left, TreeNode *right)
{
    if (!left || !right)
        return left == right;

    if (left->val != right->val)
        return false;

    return issymmetrichelp(left->left, right->right) && issymmetrichelp(left->right, right->left);
}

bool isSymmetric(TreeNode *root)
{
    return root == NULL || issymmetrichelp(root->left, root->right);
}