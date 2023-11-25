template<class T>
int Heap<T>::getItem(T item) 
{
    for (int i = 0; i < count; ++i)
        if (elements[i] == item)
            return i;
    
    return -1;
}

template<class T>
void Heap<T>::remove(T item) 
{
    int itemIndex = getItem(item);

    if (itemIndex == -1)
        return;

    swap(elements[itemIndex], elements[--count]);

    reheapDown(itemIndex);
}

template<class T>
void Heap<T>::clear() 
{
    delete[] elements;
    capacity = 10;
    count = 0;
    elements = new T[capacity];
}