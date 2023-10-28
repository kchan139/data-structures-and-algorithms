//Helping functions
Node * addHelper (Node * root, T value)
{
    if (!root) return new Node (value);
    
    if (value > root->value)
        root->pRight = addHelper (root->pRight, value);
    else
        root->pLeft = addHelper (root->pLeft, value);
        
    return root;
}

Node * delHelper (Node * root, T value)
{
    if (!root) return root;
    
    if (root->value > value)
    {
        root->pLeft = delHelper (root->pLeft, value);
        return root;
    }
    else if (root->value < value)
    {
        root->pRight = delHelper (root->pRight, value);
        return root;
    }
    
    if (!root->pLeft)
    {
        Node * tmp = root->pRight;
        delete root;
        return tmp;
    }
    else if (!root->pRight)
    {
        Node * tmp = root->pLeft;
        delete root;
        return tmp;
    }
    else 
    {
        Node * succP = root;
        Node * succ = root->pRight;
        while (succ->pLeft)
        {
            succP = succ;
            succ = succ->pLeft;
        }
        
        if (succP != root)
            succP->pLeft = succ->pRight;
        else 
            succP->pRight = succ->pRight;
            
        root->value = succ->value;
        
        delete succ;
        return root;
    }
}

void add(T value)
{
    //TODO
    this->root = addHelper (this->root, value);
}

void deleteNode(T value){
    //TODO
    this->root = delHelper (this->root, value);
}