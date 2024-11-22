for (int i = 0; i < n; i++) {
    string src = edges[i].src;
    string dst = edges[i].dst;
    int weight = edges[i].weight;

    int srcIndex = -1;
    for (int j = 0; j < nover; j++) {
        if (srclst[j].element.label == src) {
            srcIndex = j;
            break;
        }
    }
    if (srcIndex == -1) continue;

    GEdge newEdge(dst, weight);

    Link<GEdge>* current = &srclst[srcIndex];
    while (current->next != nullptr && current->next->element.label < dst) {
        current = current->next;
    }

    Link<GEdge>* newNode = new Link<GEdge>(newEdge, current->next);
    current->next = newNode;
}