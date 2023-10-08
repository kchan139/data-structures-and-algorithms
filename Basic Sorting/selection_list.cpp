template <typename E> 
void selectionSort (List<E> & L) 
{
    for (int i = 0; i < L.length() - 1; i++) 
    {
        L.moveToStart();
        E min_idx = i;
        
        for (int j = i + 1; j < L.length(); j++) 
        {
            L.moveToPos(j);
            E currValue = L.getValue();
            
            L.moveToPos(min_idx);
            E minValue = L.getValue();
            
            if (currValue < minValue)
                min_idx = j;
        }
 
        L.moveToPos(i);
        E value = L.getValue();
        
        L.moveToPos(min_idx);
        E minValue = L.getValue();
        
        if (min_idx != i) 
        {
            L.insert(value);
            L.next();
            L.remove();
            
            L.moveToPos(i);
            L.insert(minValue);
            L.next();
            L.remove();
        }
    }
}