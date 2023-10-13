template <typename E>
void qSortHelper (List<E> & L, int i, int j)
{
    if (j <= i) return;
    
    int pIndex = (i + j) / 2;
    swap (L, pIndex, j);
    
    L.moveToPos (j);
    E value = L.getValue ();
    
    int k = partition (L, i - 1, j, value);
    
    swap (L, k, j);
    qSortHelper (L, i, k-1);
    qSortHelper (L, k+1, j);
}

template <typename E>
void quickSort (List<E> & L)
{
    int i = 0, j = L.length() - 1;
    qSortHelper (L, i, j);
};