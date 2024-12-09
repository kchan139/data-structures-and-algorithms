#include <iostream>
#include <vector>
#include <list>
using namespace std;

class DirectedGraph 
{ 
	int V;
	vector<list<int>> adj;
public:
	DirectedGraph(int V)
	{
		this->V = V; 
		adj = vector<list<int>>(V, list<int>());
	}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
	bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack) {
        visited[v] = true;
        recStack[v] = true;
        
        for (int neighbor : adj[v]) {
            if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack)) {
                return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[v] = false;
        return false;
    }
	bool isCyclic()
	{
	    // Student answer
	    vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, recStack)) {
                    return true;
                }
            }
        }
        
        return false;
	}
}; 