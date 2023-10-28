template <typename E>
BNode<E> * BSTdelete(BNode<E> * root, E val) 
{
    if (!root) return root;

    if (val < root->element())
        root->setLeft (BSTdelete (root->left(), val));

    else if (val > root->element())
        root->setRight (BSTdelete (root->right(), val));
    
    else 
    {
        if (!root->left()) 
        {
            BNode<E>* temp = root->right();
            return temp;
        } 
        else if (!root->right()) 
        {
            BNode<E> * temp = root->left();
            return temp;
        }

        BNode<E> * temp = root->right();
        while (temp->left() != nullptr)
            temp = temp->left();

        root->setElement (temp->element());
        root->setRight (BSTdelete (root->right(), temp->element()));
    }
    return root;
};