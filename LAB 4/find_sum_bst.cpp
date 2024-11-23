// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
private:
bool findRec(Node* node, T value) {
    if (!node) return false;
    if (node->value == value) return true;
    
    if (value < node->value)    
        return findRec(node->pLeft, value); 
        
    return findRec(node->pRight, value);
}

T sumRec(Node* node, T l, T r) {
    if (!node) return 0; 
    
    T sum = 0;
    if (node->value >= l && node->value <= r)
        sum += node->value;
        
    if (node->value > l)
        sum += sumRec(node->pLeft, l, r);
        
    if (node->value < r)
        sum += sumRec(node->pRight, l, r);
        
    return sum;
}

public:
bool find(T i) {
    // TODO: return true if value i is in the tree; otherwise, return false.
    return findRec(root, i);
}

T sum(T l, T r) {
    // TODO: return the sum of all element in the tree has value in range [l,r].
    return sumRec(root, l, r);
}

// STUDENT ANSWER END