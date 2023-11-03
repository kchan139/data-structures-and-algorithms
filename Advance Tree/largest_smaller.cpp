template <typename E>
void LargestSmaller(BNode<E> *root, E key)
{
    vector<E> min;
    helper(root, key, min);
}

template <typename E>
void helper(BNode<E> *node, E key, vector<E> min)
{
    if (!node)
    {
        if (min.empty()) return;

        E dex = min[0];
        for (size_t i = 1; i < min.size(); ++i)
            if (dex < min[i])
                dex = min[i];

        cout << dex << endl;
    }
    else if (node->key < key)
    {
        min.push_back(node->key);
        helper(node->right, key, min);
    }
    else helper(node->left, key, min);
}


template <typename E>
class BNode
{
    public:
        E key;
        BNode<E> *left;
        BNode<E> *right;
        BNode(E v, BNode<E> *l = NULL, BNode<E> *r = NULL) : key(v), left(l), right(r) {}
};