template <typename E> 
void insertionSort(List<E> &L) 
{
    for (int i = 1; i < L.length(); i++) 
    {
        L.moveToStart();
        L.moveToPos(i - 1);
        E preValue = L.getValue();
        
        L.next();
        E value = L.getValue();
        
        for (int j = i, k = j; j > 0 && value < preValue; j--) 
        {
            L.moveToPos(j - 1);
            L.insert(value);
            L.next();
            L.next();
            L.remove();
            
            k--;
            
            if(k > 0)
            {
                L.moveToPos(k - 1);
                preValue = L.getValue();
                L.next();
                value = L.getValue();
            }
        }
    }
}