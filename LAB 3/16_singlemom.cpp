int singleChild(BSTNode* root) 
{
    // STUDENT ANSWER
    if (!root) return 0;
    
    if (!root->left && root->right)
        return 1 + singleChild (root->right);
    else if (root->left && !root->right)
        return 1 + singleChild (root->left);
    else 
        return singleChild (root->left) + singleChild (root->right);
}