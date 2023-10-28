// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

void BFS()
{
    if (!root) return;
    
    queue<Node *> q;
    q.push (root);
    
    while (!q.empty())
    {
        Node * current = q.front();
        cout << current->value << " ";
        q.pop();
        
        if (current->pLeft)
            q.push (current->pLeft);
        if (current->pRight)
            q.push (current->pRight);
    }
}
// STUDENT ANSWER END