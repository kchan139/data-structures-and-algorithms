const int MOD = 27022001;

int sumDigitPathHelper(BTNode* node, int currentSum) {
    if (!node) return 0;

    currentSum = (currentSum * 10 + node->val) % MOD;

    if (!node->left && !node->right)
        return currentSum;

    int leftSum = sumDigitPathHelper(node->left, currentSum);
    int rightSum = sumDigitPathHelper(node->right, currentSum);

    return (leftSum + rightSum) % MOD;
}

int sumDigitPath(BTNode* root) {
    return sumDigitPathHelper(root, 0);
}