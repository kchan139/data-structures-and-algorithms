void BFS(string startlabel, void (Graph::*action)(int)) {
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

    LQueue<int> queue;
    queue.enqueue(startIdx);
    visited[startIdx] = true;

    while (!queue.isEmpty()) {
        int curr = queue.dequeue();

        (this->*action)(curr);

        std::vector<int> neighbors;
        for (Link<GEdge>* edge = srclst[curr].next; edge != nullptr; edge = edge->next) {
            neighbors.push_back(edge->element.idx);
        }

        std::sort(neighbors.begin(), neighbors.end());

        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                queue.enqueue(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    
    delete[] visited;
}
