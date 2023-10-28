template <typename E>
BNode<E>* BSTsearch(BNode<E> * root,E val)
{
    if (!root) return root;
    
    E element = root->element();
    cout << element << ",";
    
    if (element == val)
        return root;
    
    if (val < element)
        return BSTsearch (root->left(), val);
    
    return BSTsearch (root->right(), val);
};