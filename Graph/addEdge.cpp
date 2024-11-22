for (int i = 0; i < n; i++) {
    string ver1 = edges[i].ver1;
    string ver2 = edges[i].ver2;
    int weight = edges[i].weight;

    int index1 = -1, index2 = -1;
    for (int j = 0; j < nover; j++) {
        if (labels[j] == ver1) index1 = j;
        if (labels[j] == ver2) index2 = j;
    }
    if (index1 != -1 && index2 != -1) {
        wm[index1][index2] = weight;
        wm[index2][index1] = weight;
    }
}