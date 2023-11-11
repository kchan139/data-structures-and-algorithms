bool searchHelper (Node * node, T value)
{
    if (!node) return false;

    if (node->data == value)
        return true;

    if (value < node->data)
        return searchHelper(node->pLeft, value); 
    
    return searchHelper(node->pRight, value);
}

bool search (T value)
{
    return searchHelper (this->root, value);
}

void pInorderHelper (Node * node)
{
    if (!node) return;
    
    pInorderHelper (node->pLeft);
    cout << node->data << " ";
    pInorderHelper (node->pRight);
    
}

void printInorder ()
{
    pInorderHelper (this->root);
}