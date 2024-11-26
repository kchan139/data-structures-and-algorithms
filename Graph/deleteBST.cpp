void deleteNode(T value)
{
    root = deleteRec(root, value);
}

Node *findMax(Node *node)
{
    while (node->pRight)
        node = node->pRight;

    return node;
}

Node *deleteRec(Node *root, T value)
{
    if (!root) return nullptr;

    if (value < root->value)
        root->pLeft = deleteRec(root->pLeft, value);

    else if (value > root->value)
        root->pRight = deleteRec(root->pRight, value);

    else
    {
        if (!root->pLeft && !root->pRight)
        {
            delete root;
            return nullptr;
        }
        else if (!root->pLeft)
        {
            Node *temp = root->pRight;
            delete root;
            return temp;
        }
        else if (!root->pRight)
        {
            Node *temp = root->pLeft;
            delete root;
            return temp;
        }
        else
        {
            Node *predecessor = findMax(root->pLeft);
            root->value = predecessor->value;
            root->pLeft = deleteRec(root->pLeft, predecessor->value);
        }
    }
    return root;
}