Node* remove(int val) 
{
    if (root == nullptr) 
        return nullptr;

    Node* foundNode = searchNode(root, val);
    splay(foundNode);

    if (root->val != val)
        return nullptr;

    Node* tree1 = root->pLeft;
    Node* tree2 = root->pRight;

    if (tree1 == nullptr) 
    {
        root = tree2;
        if (root)
            root->pParent = nullptr;

        return foundNode;
    }

    root = findLargestAndSplay(tree1);
    root->pRight = tree2;
    if (tree2)
        tree2->pParent = root;

    return foundNode;
}

Node* findLargestAndSplay(Node* node) 
{
    while (node->pRight != nullptr)
        node = node->pRight;
    
    splay(node);
    return node;
}

Node* searchNode(Node* node, int val) 
{
    if (node == nullptr || node->val == val)
        return node;

    if (val < node->val) 
    {
        if (node->pLeft == nullptr)
            return node;
            
        return searchNode(node->pLeft, val);
    }
    else 
    {
        if (node->pRight == nullptr)
            return node;

        return searchNode(node->pRight, val);
    }
}
