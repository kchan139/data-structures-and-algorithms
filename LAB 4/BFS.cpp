// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

void BFS() 
{
    if (!this->root) return;

    queue<Node*> q;
    q.push(this->root);

    bool isFirst = true;
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (!isFirst)
            cout << " ";
            
        cout << current->value;
        isFirst = false;

        if (current->pLeft)
            q.push(current->pLeft);
        if (current->pRight)
            q.push(current->pRight);
    }
    cout << endl;
}
// STUDENT ANSWER END