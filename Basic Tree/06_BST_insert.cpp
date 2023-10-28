template <typename E>
BNode<E>* BSTinsert(BNode<E> * root,E val)
{
    if (!root) return new BNode<E> (val);

    if (val < root->element())
        root->setLeft (BSTinsert (root->left(), val));
    else
        root->setRight (BSTinsert (root->right(), val));
    
    return root;
};