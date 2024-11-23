int rangeCount(BTNode* root, int lo, int hi) {
    if (!root) return 0;

    int count = 0;if (root->val >= lo && root->val <= hi)
        count = 1;
        
    if (root->val > lo)
        count += rangeCount(root->left, lo, hi);
        
    if (root->val <= hi)
        count += rangeCount(root->right, lo, hi);

    return count;
}