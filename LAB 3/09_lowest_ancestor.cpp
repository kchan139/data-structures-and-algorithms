BTNode * helper (BTNode * root, int a, int b)
{
    if (!root) return nullptr;
    
    if (root->val == a || root->val == b)
        return root;
        
    BTNode * left = helper (root->left, a, b);
    BTNode * right = helper (root->right, a, b);
    
    if (left && right) return root;
    
    return (left)? left : right;
}

int lowestAncestor(BTNode* root, int a, int b) 
{
    BTNode * result = helper (root, a, b);
    if (!result) return 0;
    return result->val;
}