template <typename E> 
int partition (List<E> & L, int low, int high, E & pivot)
{
    do
    {
        L.moveToPos (++low);
        while (L.getValue() < pivot)
        {
            L.next();
            ++low;
        }
        
        while ((low < high) && pivot < L.getValue())
            L.moveToPos (--high);
        
        swap (L, low, high);
    }
    while (low < high);
    
    return low;
};