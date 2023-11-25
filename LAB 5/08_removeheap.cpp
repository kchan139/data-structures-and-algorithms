template<class T>
int Heap<T>::getItem(T item) 
{
    for (int i = 0; i < count; i++)
        if (elements[i] == item)
            return i;

    return -1;
}

template<class T> 
void Heap<T>::remove(T item) 
{
    int index = getItem(item);

    if (index == -1)
        return;

    elements[index] = elements[count-1];

    if (index < count-1)
        reheapDown(index);

    if (index > 0)
        reheapUp(index);

    count--;
}

template<class T>
void Heap<T>::clear() 
{
    count = 0;
}