void topologicalSort(void (Graph::*action)(int)) 
{
    int inDegree[nover];
    for (int i = 0; i < nover; i++)
        inDegree[i] = 0;
    
    for (int i = 0; i < nover; i++) 
    {
        Link<GEdge>* edge = srclst[i].next;
        while (edge) 
        {
            inDegree[edge->element.idx]++;
            edge = edge->next;
        }
    }
    
    
    LQueue<int> zeroInDegreeQueue;
    for (int i = 0; i < nover; i++)
        if (inDegree[i] == 0)
            zeroInDegreeQueue.enqueue(i);
            
    
    while (!zeroInDegreeQueue.isEmpty()) {
        int v = zeroInDegreeQueue.dequeue();
    
        (this->*action)(v);
    
        Link<GEdge>* edge = srclst[v].next;
        while (edge) 
        {
            int neighbor = edge->element.idx;
            inDegree[neighbor]--;
    
            if (inDegree[neighbor] == 0)
                zeroInDegreeQueue.enqueue(neighbor);
    
            edge = edge->next;
        }
    }
}