// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
int heightHelper (Node * root)
{
    if (!root) return 0;
    
    int l = heightHelper (root->pLeft);
    int r = heightHelper (root->pRight);
    
    return (l > r)? l + 1 : r + 1;
}

void preHelper (Node * root)
{
    if (!root) return;
    
    cout << root->value << " ";
    preHelper (root->pLeft);
    preHelper (root->pRight);
}

void inHelper (Node * root)
{
    if (!root) return;
    
    inHelper (root->pLeft);
    cout << root->value << " ";
    inHelper (root->pRight);
}

void postHelper (Node * root)
{
    if (!root) return;
    
    postHelper (root->pLeft);
    postHelper (root->pRight);
    cout << root->value << " ";
}

int getHeight() {
    // TODO: return height of the binary tree.
    return heightHelper (this->root);
}

string preOrder() {
    // TODO: return the sequence of values of nodes in pre-order.
    preHelper (this->root);
    return "";
}

string inOrder() {
    // TODO: return the sequence of values of nodes in in-order.
    inHelper (this->root);
    return "";
}

string postOrder() {
    // TODO: return the sequence of values of nodes in post-order.
    postHelper (this->root);
    return "";
}

// STUDENT ANSWER END