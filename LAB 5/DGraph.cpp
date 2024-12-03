template<class T>
typename DGraph<T>::Edge* DGraph<T>::VertexNode::getEdge(VertexNode* toNode) {
    //TODO: Iterate through the adjacency list of this vertex
    //      checking if there exists an edge with this vertex as the starting vertex 
    //      and "toNode" as the ending vertex. 
    //      If not return nullptr, else return that edge.
    Edge* currentEdge = adList;
    while (currentEdge != nullptr) 
    {
        if (currentEdge->toNode == toNode)
            return currentEdge;
            
        currentEdge = currentEdge->next;
    }
    return nullptr;
}

template<class T>
void DGraph<T>::VertexNode::addAdjacentEdge(Edge* newEdge) {
    //TODO: add newEdge to adjacency list of this vertex.
    newEdge->next = adList;
    adList = newEdge;
}

template<class T>
bool DGraph<T>::VertexNode::connectTo(VertexNode* toNode, float weight) {
    //TODO: get edge from this node to "toNode".
    
    //TODO: If the edge is not existed, create a new Edge and add it to the adjacency list. 
    //      If the edge is existed, update its weight.
    
    //TODO: Return true if a new Edge is created; otherwise, return false.
    
    Edge* existingEdge = getEdge(toNode);
    if (existingEdge != nullptr) 
    {
        existingEdge->weight = weight;
        return false;
    } 
    else 
    {
        Edge* newEdge = new Edge(this, toNode, weight);
        addAdjacentEdge(newEdge);
        return true;
    }
}

template<class T>
bool DGraph<T>::VertexNode::removeTo(VertexNode *toNode) {
    //TODO: remove the edge with "toNode" as the ending vertex from this node's adjacency list.
    
    //TODO: return true if success; otherwise, return false.
    
    Edge* currentEdge = adList;
    Edge* previousEdge = nullptr;

    while (currentEdge != nullptr) {
        if (currentEdge->toNode == toNode) 
        {
            if (previousEdge == nullptr) 
                adList = currentEdge->next;
            else 
                previousEdge->next = currentEdge->next;
                
            delete currentEdge;
            return true;
        }
        
        previousEdge = currentEdge;
        currentEdge = currentEdge->next;
    }
    return false;
}
