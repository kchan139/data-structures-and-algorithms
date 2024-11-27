// edgeidx* mst_prim() {
    if (nover < 1) return nullptr;

    int dist[nover];
    int parent[nover];
    bool visited[nover];
    edgeidx * mst_edges = new edgeidx[nover - 1]; 

    for (int i = 0; i < nover; i++) 
    {
        dist[i] = INT_MAX; 
        visited[i] = false;
        parent[i] = -1;
    }

    dist[0] = 0;
    int mst_size = 0;

    for (int i = 0; i < nover; i++) 
    {
        int u = -1;
        int minDist = INT_MAX;

        for (int v = 0; v < nover; v++) 
        {
            if (!visited[v] && dist[v] < minDist) 
            {
                u = v;
                minDist = dist[v];
            }
        }

        visited[u] = true;
        
        for (int v = 0; v < nover; v++) 
        {
            if (wm[u][v] != INT_MAX && !visited[v] && wm[u][v] < dist[v]) 
            {
                dist[v] = wm[u][v];
                parent[v] = u;
            }
        }

        if (parent[u] != -1 && u != parent[u]) 
        {
            mst_edges[mst_size].idx1 = parent[u];
            mst_edges[mst_size].idx2 = u;
            mst_size++;
        }
    }

    return mst_edges;
// }