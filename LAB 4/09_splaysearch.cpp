bool search(int val) 
{
    Node* foundNode = searchNode(root, val);

    if (foundNode) 
    {
        splay(foundNode);
        if (root->val == val)
            return true;
    }

    return false;
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
