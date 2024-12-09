void dfs(int u, vector<vector<int>>& friends, vector<bool>& visited) {
    stack<int> s;
    s.push(u);
    visited[u] = true;
    
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        
        for (int neighbor : friends[v]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}

int numberOfFriendGroups(vector<vector<int>>& friends) {
    // STUDENT ANSWER
    int n = friends.size();
    vector<bool> visited(n, false);
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, friends, visited);
            count++;
        }
    }
    
    return count;
}