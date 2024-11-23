vector<int> levelAlterTraverse(BSTNode* root) {
    // STUDENT ANSWER
    vector<int> result;
    if (!root) return result;

    queue<BSTNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;

        for (int i = 0; i < levelSize; ++i) {
            BSTNode* current = q.front();
            q.pop();
            level.push_back(current->val);

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        if (!leftToRight)
            reverse(level.begin(), level.end());
            
        leftToRight = !leftToRight;

        result.insert(result.end(), level.begin(), level.end());
    }

    return result;
}