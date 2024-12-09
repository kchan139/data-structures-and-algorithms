template <class T>
bool DGraph<T>::removeEdge(T from, T to) {
    //TODO: get vertexNode with "from" and vertexNode with "to".
        
    //TODO: If either of the two vertexNode objects does not exist, 
    //      throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    
    //TODO: Delete the edge between the "from" vertexNode and the "to" vertexNode. (use removeTo method)
    //      If success return true and decrement the countEdge; otherwise, return false; 
    VertexNode* fromNode = getVertexNode(from);
    VertexNode* toNode = getVertexNode(to);

    if (!fromNode || !toNode) {
        throw VertexNotFoundException("Vertex doesn't exist!");
    }

    bool success = fromNode->removeTo(toNode);
    if (success) {
        countEdge--;
    }
    return success;
}

template <class T>
void DGraph<T>::removeVertex(T removeVertex) {
    //TODO: get vertexNode with "removeVertex"
        
    //TODO: If this vertexNode isn't existed,
    //      throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    
    //TODO: Iterate through all the vertexNode in the graph's Node list. For each vertexNode:
    //      - Check for an edge from the current vertex to the "removeVertex". 
    //      If such an edge exists, delete it (use removeTo method) and decrement the countEdge. 
    
    //      - Check for an edge from the "removeVertex" to the current vertex. 
    //      If such an edge exists, delete it (use removeTo method) and decrement the countEdge.
    
    //TODO: Delete the vertexNode containing removeVertex from the Node list of the graph
    //      Decrement the countVertex.
    VertexNode* removeNode = getVertexNode(removeVertex);

    if (!removeNode) {
        throw VertexNotFoundException("Vertex doesn't exist!");
    }

    // Remove edges from all other vertices to this vertex
    VertexNode* currNode = nodeList;
    while (currNode) {
        if (currNode != removeNode) {
            if (currNode->removeTo(removeNode)) {
                countEdge--;
            }
        }
        currNode = currNode->next;
    }

    // Remove edges from this vertex to all other vertices
    Edge* adjEdge = removeNode->adList;
    while (adjEdge) {
        VertexNode* toNode = adjEdge->toNode;
        if (toNode) {
            toNode->removeTo(removeNode);
            countEdge--;
        }
        adjEdge = adjEdge->next;
    }

    // Remove the node from the nodeList
    if (nodeList == removeNode) {
        nodeList = removeNode->next;
    } else {
        VertexNode* prevNode = nodeList;
        while (prevNode && prevNode->next != removeNode) {
            prevNode = prevNode->next;
        }
        if (prevNode) {
            prevNode->next = removeNode->next;
        }
    }

    delete removeNode;
    countVertex--;
}