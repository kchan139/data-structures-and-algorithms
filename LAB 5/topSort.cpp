void topologicalSortUtil(int v, bool visited[], stack<int>& Stack) {
    visited[v] = true;

    for (int i = 0; i < adj[v].getSize(); i++) {
        int neighbor = adj[v].getElement(i);
        if (!visited[neighbor]) {
            topologicalSortUtil(neighbor, visited, Stack);
        }
    }

    Stack.push(v);
}
void topologicalSort(){
    //TODO
    stack<int> Stack;
    bool* visited = new bool[V]();
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}