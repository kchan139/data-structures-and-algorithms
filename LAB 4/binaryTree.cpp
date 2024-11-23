// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
private:
int calculateHeight(Node* node) {
    if (!node) return 0;
    return 1 + max(calculateHeight(node->pLeft), calculateHeight(node->pRight));
}

void preOrderTraversal(Node* node, ostringstream& oss) {
    if (!node) return;
    oss << node->value << " ";
    preOrderTraversal(node->pLeft, oss);
    preOrderTraversal(node->pRight, oss);
}

void inOrderTraversal(Node* node, ostringstream& oss) {
    if (!node) return;
    inOrderTraversal(node->pLeft, oss);
    oss << node->value << " ";
    inOrderTraversal(node->pRight, oss);
}

void postOrderTraversal(Node* node, ostringstream& oss) {
    if (!node) return;
    postOrderTraversal(node->pLeft, oss);
    postOrderTraversal(node->pRight, oss);
    oss << node->value << " ";
}

public:
int getHeight() {
    // TODO: return height of the binary tree.
    return calculateHeight(this->root);
}

string preOrder() {
    // TODO: return the sequence of values of nodes in pre-order.
    ostringstream oss;
    preOrderTraversal(this->root, oss);
    return oss.str();
}

string inOrder() {
    // TODO: return the sequence of values of nodes in in-order.
    ostringstream oss;
    inOrderTraversal(this->root, oss);
    return oss.str();
}

string postOrder() {
    // TODO: return the sequence of values of nodes in post-order.
    ostringstream oss;
    postOrderTraversal(this->root, oss);
    return oss.str();
}

// STUDENT ANSWER END