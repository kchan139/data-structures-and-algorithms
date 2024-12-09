// Some helping functions

int Dijkstra(int** graph, int src, int dst) {
	// TODO: return the length of shortest path from src to dst.
	int n = 6;
	vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); 
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (u == dst)
            return dist[u];
    
        
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0) {
                int weight = graph[u][v];
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    
    return -1;
}