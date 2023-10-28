template <typename E>
void BFtraversal(BNode<E> * root, void (*f)(E))
{
    if (!root) return;

    LQueue<BNode<E> *> q;
    q.enqueue(root);
    
    while (q.length() > 0)
    {
        BNode<E> * node = q.dequeue();
        f (node->element());

        if (node->left()) q.enqueue(node->left());
        if (node->right()) q.enqueue(node->right());
    }
};