template <typename E>
int height (BNode<E> * root)
{
    if (!root) return 0;
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        return 1 + (l > r ? l : r);
    }
};