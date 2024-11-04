int doubleHashing(int key, int i) {
    //To Do
    int h1 = key % listSize;
    
    int h2 = (listSize / 2) - (key % (listSize / 2));
    
    return (h1 + i * h2) % listSize;
}
