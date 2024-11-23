// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
int countTwoChildrenNodeHelper(Node* node) {
    if (node == nullptr)
        return 0;
    
    int count = 0;
    if (node->pLeft != nullptr && node->pRight != nullptr)
        count = 1;

    return count + countTwoChildrenNodeHelper(node->pLeft) + countTwoChildrenNodeHelper(node->pRight);
}

int countTwoChildrenNode() {
    return countTwoChildrenNodeHelper(this->root);
}
// STUDENT ANSWER END