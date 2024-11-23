BSTNode * helper (BSTNode * root, int k, int & count)
{
    if (!root) return root;
    
    BSTNode * left = helper (root->left, k, count);
    
    if (left) return left;
    
    count++;
    if (count == k)
        return root;
    
    return helper (root->right, k, count);
}

int kthSmallest(BSTNode* root, int k) 
{
    int count = 0;
    
    BSTNode * result = helper (root, k, count);
    
    return (result) ? result->val : 0;
    
}