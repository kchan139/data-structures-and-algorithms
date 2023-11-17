template <typename E>
void heapSort(List<E> & L)
{
    makeHeap(L);
    int heapsize = L.length();

    for (int i = heapsize - 1; i >= 0; --i) 
    {
        L.moveToStart();
        E min = L.getValue();

        L.moveToPos(i);
        E last = L.getValue();

        L.moveToStart();
        L.remove();
        L.insert(last);

        L.moveToPos(i);
        L.remove();
        L.insert(min);

        reheapDown(L, i, 0);
    }
};