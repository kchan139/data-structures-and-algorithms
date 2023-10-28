template <typename E>
bool isBSTUtil(BNode<E>* node, E minVal, E maxVal) 
{
    if (!node) return true;

    if (node->element() < minVal || node->element() > maxVal)
        return false;

    return isBSTUtil(node->left(), minVal, node->element()) && 
           isBSTUtil(node->right(), node->element(), maxVal);
}

template <typename E>
bool isBST(BNode<E>* root) 
{
    if (!root) return false;  

    return isBSTUtil(root, numeric_limits<E>::min(), numeric_limits<E>::max());
}
