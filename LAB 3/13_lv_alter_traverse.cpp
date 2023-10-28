vector<int> levelAlterTraverse(BSTNode* root) 
{
    vector<int> result;
    if (!root) return result;

    queue<BSTNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) 
    {
        int levelSize = q.size();
        stack<int> stack;

        for (int i = 0; i < levelSize; ++i) 
        {
            BSTNode* current = q.front();
            q.pop();

            if (leftToRight)
                result.push_back(current->val);
            else
                stack.push(current->val);
        

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        while (!stack.empty()) 
        {
            result.push_back(stack.top());
            stack.pop();
        }

        leftToRight = !leftToRight;
    }

    return result;
}