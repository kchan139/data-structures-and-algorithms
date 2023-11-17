template <typename E> 
void makeHeap(List<E> &L)
{
    int heapsize = L.length();
    for (int i = heapsize / 2 - 1; i >= 0; i--) 
        reheapDown(L, heapsize, i);
};