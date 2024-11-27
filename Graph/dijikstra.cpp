// void dijikstra(string label) 
// {
    int src = -1;
    for (int i = 0; i < nover && src == -1; i++)
        if (label == labels[i])
            src = i;

    if (src == -1) return;

    int dist[nover];
    bool visited[nover];
    for (int i = 0; i < nover; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < nover; i++) 
    {
        int u = -1;
        int minDist = INT_MAX;
        for (int j = 0; j < nover; j++) 
        {
            if (!visited[j] && dist[j] < minDist) 
            {
                u = j;
                minDist = dist[j];
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < nover; v++) 
        {
            if (wm[u][v] != INT_MAX && !visited[v]) 
            {
                int newDist = dist[u] + wm[u][v];
                
                if (newDist < dist[v])
                    dist[v] = newDist;
            }
        }
    }

    for (int i = 0; i < nover; i++) 
    {
        if (dist[i] == INT_MAX)
            cout << "infinite";
        else
            cout << dist[i];
        
        if (i < nover - 1) cout << ",";
    }
    cout << endl;
// }
