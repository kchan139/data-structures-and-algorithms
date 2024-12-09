template<class T>
typename DGraph<T>::VertexNode* DGraph<T>::getVertexNode(T vertex) {
    //TODO: Iterate through the Node list of the graph 
    //      check if any vertexNode contains vertex. 
    //      If such a vertexNode exists, return it; otherwise, return nullptr.
    
    VertexNode *cur_vertex = nodeList;
    
    while (cur_vertex != nullptr) {
        if (cur_vertex->vertex == vertex)
            return cur_vertex;

        cur_vertex = cur_vertex->next;
    }
    
    return nullptr;
}

template<class T>
void DGraph<T>::add(T vertex) {
    //TODO: create a new vertexNode with vertex.
    
    //TODO: add new vertexNode to the end of Node list of the graph.
    
    //TODO: increase the countVertex.
    
    if (nodeList == nullptr)
        nodeList = new VertexNode(vertex);
    else {
        VertexNode *cur_vertex = nodeList;
        while (cur_vertex != nullptr && cur_vertex->next != nullptr) {
            if (cur_vertex->vertex == vertex)
                return;
            
            cur_vertex = cur_vertex->next;
        }
        cur_vertex->next = new VertexNode(vertex);
    }
    
    countVertex++;
}

template <class T>
void DGraph<T>::connect(T from, T to, float weight) {
    //TODO: get vertexNode with "from" and vertexNode with "to".
    
    //TODO: If either of the two vertexNode objects does not exist, 
    //      throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    
    //TODO: connect "from" vertexNode to "to" vertexNode. 
    //      If a new edge is created, increase the countEdge.
    VertexNode *vertex_from = this->getVertexNode(from);
    VertexNode *vertex_to = this->getVertexNode(to);
    
    if (!vertex_from || !vertex_to)
        throw VertexNotFoundException("Vertex doesn't exist!");
        
    if(vertex_from->connectTo(vertex_to, weight))
        countEdge++;
    
}