template <typename E>
void reheapDown(List<E> & L, int heapsize, int startpos) 
{
    if (L.length() < heapsize)
        throw out_of_range("Heap size cannot be greater than the length of the list");

    int parent = startpos;
    int child  = 2 * parent + 1;  

    L.moveToPos(parent);
    E parentValue = L.getValue();

    while (child < heapsize) 
    {
        L.moveToPos(child);
        E childValue = L.getValue();

        if (child + 1 < heapsize) 
        {
            L.moveToPos(child + 1);
            E rightChildValue = L.getValue();
            
            if (childValue > rightChildValue) 
            {
                childValue = rightChildValue;
                child++;
            }
        }

        if (parentValue > childValue) 
        {
            L.moveToPos(parent);
            L.remove();
            L.insert(childValue);

            L.moveToPos(child);
            L.remove();
            L.insert(parentValue);

            parent = child;
            child = 2 * parent + 1;
        } 
        else break;
    }
};