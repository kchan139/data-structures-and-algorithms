template <class E>
void printGreatestSmaller(E key) 
{
    BNode<E>* node = root;
    E greatestSmaller = -1;

    while (node != NULL) 
    {
        if (node->key < key) 
        {
            greatestSmaller = node->key;
            node = node->right;
        } 
        else node = node->left;
    }
    
    if (greatestSmaller != -1) cout << greatestSmaller;
};