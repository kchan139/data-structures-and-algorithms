//Helping functions
int getBF(Node * root)
{
    if (!root) return 0;
    
    return getHeightRec (root->pLeft) - getHeightRec (root->pRight);
}

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

Node * insertHelper (Node * node, const T &value)
{
    if (!node) return new Node (value);
    
    if (value < node->data)
        node->pLeft = insertHelper (node->pLeft, value);
    else 
        node->pRight = insertHelper (node->pRight, value);
    
    int bf = getBF (node);
    
    if (bf > 1 && value < node->pLeft->data)  
        return rotateRight (node);  
  
    if (bf < -1 && value >= node->pRight->data)  
        return rotateLeft (node);  
        
        
    if (bf > 1 && value >= node->pLeft->data)  
    {  
        node->pLeft = rotateLeft (node->pLeft);  
        return rotateRight (node);  
    }  
  
    if (bf < -1 && value < node->pRight->data)  
    {  
        node->pRight = rotateRight (node->pRight);  
        return rotateLeft (node);  
    }  
    
    return node;
}

void insert(const T &value){
    //TODO
    this->root = this->insertHelper (this->root, value);
}