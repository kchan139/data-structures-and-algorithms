void bfs(int start, vector<vector<int>>& edges, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : edges[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int connectedComponents(vector<vector<int>>& edges) {
    // STUDENT ANSWER
    int n = edges.size();
    vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            bfs(i, edges, visited);
            count++;
        }
    }
    return count;
}