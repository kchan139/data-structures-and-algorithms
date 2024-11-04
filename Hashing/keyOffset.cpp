int keyOffset(int key, int i) {
    //To Do
    int base = key % listSize;
    int offset = (key / listSize) + 1;
    
    return (base + i * offset) % listSize;
}
