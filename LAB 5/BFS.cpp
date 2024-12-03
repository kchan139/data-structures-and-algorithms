#include <queue>

class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	Adjacency *getAdj () { return this->adj; }
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *BFS(int v)
    {
        // v is a vertex we start BFS
        bool *visited = new bool[V]();
        queue<int> q;
        Adjacency *bfsOrder = new Adjacency();
        
        visited[v] = true;
        q.push(v);
    
        while (!q.empty()) 
        {
            int current = q.front();
            q.pop();
            
            bfsOrder->push(current);
    
            int adjSize = adj[current].getSize();
            for (int i = 0; i < adjSize; ++i) {
                int neighbor = adj[current].getElement(i);
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    
        delete[] visited;
        
        return bfsOrder;
	}
};