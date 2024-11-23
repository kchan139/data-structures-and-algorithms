// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

T getMin() {
    //TODO: return the minimum values of nodes in the tree.
    if (!root) return INT32_MAX;
    
    Node* current = root;
    while (current->pLeft)
        current = current->pLeft;
        
    return current->value;
}

T getMax() {
    //TODO: return the maximum values of nodes in the tree.
    if (!root) return INT32_MIN;
    
    Node* current = root;
    while (current->pRight)
        current = current->pRight;
        
    return current->value;
}

// STUDENT ANSWER END