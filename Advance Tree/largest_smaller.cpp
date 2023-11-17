template <typename E>
void LargestSmaller(BNode<E> *root, E key)
{
    if (!root) return;

    E result = -1;

    while (root)
    {
        if (root->element() < key)
        {
            result = root->element();
            root = root->right();
        }
        else root = root->left();
    }

    if (result != -1) cout << result;
};