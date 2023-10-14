void bfs(vector<vector<int>> graph, int start) 
{
    int size = graph.size();
    vector<bool> visited(size, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) 
    {
        int node = q.front();
        cout << node << " ";
        q.pop();

        for (int neighbor : graph[node]) 
        {
            if (!visited[neighbor]) 
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}