template <typename E>
void LNRtraversal(BNode<E> * root, void (*f)(E))
{
    if (!root) return;
    
    LNRtraversal (root->left(), f);
    f (root->element());
    LNRtraversal (root->right(), f);
};