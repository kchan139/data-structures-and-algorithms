template <typename E> 
void bubbleSort (List<E> & L) 
{
    L.moveToStart();
    for (int i = 0; i < L.length() - 1; i++) 
    {
        for (int j = 0; j < L.length() - i - 1; j++) 
        {
            L.moveToPos(j);
            E currentValue = L.getValue();
            
            L.next();
            E nextValue = L.getValue();
            
            if(currentValue > nextValue)
            {
                L.prev();
                L.insert(nextValue);
                L.next();
                L.next();
                L.remove();
            }
        }
    }
};