BTNode* findLowestAncestor(BTNode* root, int a, int b) {
    if (!root) return nullptr;

    if (root->val == a || root->val == b) 
        return root;

    BTNode* leftLCA = findLowestAncestor(root->left, a, b);
    BTNode* rightLCA = findLowestAncestor(root->right, a, b);

    if (leftLCA && rightLCA)    
        return root;

    return leftLCA ? leftLCA : rightLCA;
}

int lowestAncestor(BTNode* root, int a, int b) {
    BTNode* lca = findLowestAncestor(root, a, b);
    return lca ? lca->val : -1;
}