void helper (BTNode * root, int sum, int len, int &maxLen, int &maxSum)
{
    if (!root)
    {
        if (maxLen < len)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (maxLen == len && maxSum < sum)
            maxSum = sum;
            
        return;
    }
    
    helper (root->left, sum + root->val, len + 1, maxLen, maxSum);
    helper (root->right, sum + root->val, len + 1, maxLen, maxSum);
}

int longestPathSum (BTNode* root) 
{
    if (!root) return 0;
    
    int maxSum = INT32_MIN;
    int maxLen = 0;
    
    helper (root, 0, 0, maxLen, maxSum);
    
    return maxSum;
}