long long sumDigitPathUtil(BTNode* root, long long num) 
{
    if (!root) return 0;

    num = (num * 10 + root->val) % 27022001;

    if (!root->left && !root->right)
        return num;

    return (sumDigitPathUtil(root->left, num) + 
            sumDigitPathUtil(root->right, num)) % 27022001;
}

int sumDigitPath(BTNode* root) {
    return sumDigitPathUtil(root, 0);
}