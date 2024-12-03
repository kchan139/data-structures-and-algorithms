#include <stack>
#include <vector>

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
	
	Adjacency *DFS(int v)
    {
        // v is a vertex we start DFS
        bool *visited = new bool[V]();
        stack<int> s;
        Adjacency *dfsOrder = new Adjacency();

        s.push(v);

        while (!s.empty())
        {
            int current = s.top();
            s.pop();

            if (!visited[current])
            {
                visited[current] = true;
                dfsOrder->push(current);
            }

            int adjSize = adj[current].getSize();
            
            vector<int> neighbors;
            for (int i = 0; i < adjSize; i++)
            {
                int neighbor = adj[current].getElement(i);
                if (!visited[neighbor])
                    neighbors.push_back(neighbor);
            }
            
            for (int i = neighbors.size() - 1; i >= 0; i--)
                s.push(neighbors[i]);
        }

        delete[] visited;
        return dfsOrder;
	}
};