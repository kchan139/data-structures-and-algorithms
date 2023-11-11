Node* rotateRight(Node* root) 
{
    //TODO: Rotate and return new root after rotate
    Node * newRoot = root->pLeft;
    root->pLeft = newRoot->pRight;

    newRoot->pRight = root;

    return newRoot;
}

Node* rotateLeft(Node* root) 
{
    //TODO: Rotate and return new root after rotate
    Node * newRoot = root->pRight;
    root->pRight = newRoot->pLeft;
    
    newRoot->pLeft = root;
    
    return newRoot;
}