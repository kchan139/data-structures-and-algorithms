//Helping functions
int getBF(Node * root)
{
    if (!root) return 0;
    
    return getHeightRec (root->pLeft) - getHeightRec (root->pRight);
}

Node * maxValNode (Node * node)
{
    Node * curr = node;
    while (curr->pRight)
        curr = curr->pRight;
        
    return curr;
}

Node * removeHelper (Node * root, const T & value)
{
    if (!root) return root;

    if (value < root->data)
        root->pLeft = removeHelper (root->pLeft, value);
    else if (value > root->data)
        root->pRight = removeHelper (root->pRight, value);
    else
    {
        if (!(root->pLeft && root->pRight))
        {
            Node * tmp = root->pLeft ? root->pLeft : root->pRight;

            if (!tmp)
            {
                // If no child, just delete the current node
                delete root;
                return nullptr;
            }
            else
            {
                // Copy the content of the non-null child and delete it
                *root = *tmp;
                delete tmp;
            }
        }
        else
        {
            // Node with two children
            Node * tmp = maxValNode (root->pLeft);  // Use maxValNode function
            root->data = tmp->data;
            root->pLeft = removeHelper (root->pLeft, tmp->data);
        }
    }

    int balance = getBF (root);

    if (balance > 1 && getBF (root->pLeft) >= 0)
        return rotateRight (root);

    if (balance > 1 && getBF (root->pLeft) < 0)
    {
        root->pLeft = rotateLeft (root->pLeft);
        return rotateRight (root);
    }

    if (balance < -1 && getBF (root->pRight) <= 0)
        return rotateLeft (root);

    if (balance < -1 && getBF (root->pRight) > 0)
    {
        root->pRight = rotateRight (root->pRight);
        return rotateLeft (root);
    }

    return root;
}

void remove (const T & value)
{
    this->root = this->removeHelper (this->root, value);
}