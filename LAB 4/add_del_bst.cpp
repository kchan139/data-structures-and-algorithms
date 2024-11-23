//Helping functions
private:
Node* addRec(Node* node, T value) {
    if (!node) return new Node(value);

    if (value <= node->value)
        node->pLeft = addRec(node->pLeft, value);
    else
        node->pRight = addRec(node->pRight, value);

    return node;
}

Node* deleteRec(Node* node, T value) {
    if (!node) return nullptr;

    if (value < node->value)
        node->pLeft = deleteRec(node->pLeft, value);
    else if (value > node->value)
        node->pRight = deleteRec(node->pRight, value);
    else {
        if (!node->pLeft) {
            Node* temp = node->pRight;
            delete node;
            return temp;
        } 
        else if (!node->pRight) {
            Node* temp = node->pLeft;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->pRight);

        node->value = temp->value;

        node->pRight = deleteRec(node->pRight, temp->value);
    }

    return node;
}

Node* findMin(Node* node) {
    while (node && node->pLeft) {
        node = node->pLeft;
    }
    return node;
}

public:
void add(T value){
    //TODO
    root = addRec(root, value);
}

void deleteNode(T value){
    //TODO
    root = deleteRec(root, value);
}