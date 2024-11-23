BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) 
{
    if (!root) return nullptr;

    if (root->val < lo)
        return subtreeWithRange(root->right, lo, hi);
    else if (root->val > hi)
        return subtreeWithRange(root->left, lo, hi);
    else 
    {
        root->left = subtreeWithRange(root->left, lo, hi);
        root->right = subtreeWithRange(root->right, lo, hi);
        return root;
    }
}