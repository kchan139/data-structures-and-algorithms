template <typename E>
int count(BNode<E> * root)
{
    if (!root) return 0;
 
    int left = count(root->left());
    int right = count(root->right());
 
    return 1 + left + right;
};