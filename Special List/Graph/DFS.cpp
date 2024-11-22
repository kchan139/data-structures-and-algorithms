void DFS(string startlabel, void (Graph::*action)(int)) {
    int startIdx = -1;
    for (int i = 0; i < nover; i++) {
        if (labels[i] == startlabel) {
            startIdx = i;
            break;
        }
    }
    if (startIdx == -1) return;

    bool* visited = new bool[nover];
    for (int i = 0; i < nover; i++) visited[i] = false;

    AStack<int> stack;
    stack.push(startIdx);
    visited[startIdx] = true;

    while (!stack.isEmpty()) {
        int curr = stack.pop();

        (this->*action)(curr);

        std::vector<int> neighbors;
        for (Link<GEdge>* edge = srclst[curr].next; edge != nullptr; edge = edge->next) {
            neighbors.push_back(edge->element.idx);
        }

        std::sort(neighbors.begin(), neighbors.end());

        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                stack.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    
    delete[] visited;
}
