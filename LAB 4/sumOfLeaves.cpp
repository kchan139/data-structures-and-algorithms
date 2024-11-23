//Helping functions
int helper (Node * node) {
    if (node == nullptr)
        return 0;
    
    if (node->pLeft == nullptr && node->pRight == nullptr)
        return node->value;

    return helper(node->pLeft) + helper(node->pRight);
}

int sumOfLeafs(){
    //TODO
    return helper (this->root);
}