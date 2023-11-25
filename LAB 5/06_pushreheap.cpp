template<class T>
void Heap<T>::push(T item) 
{
    ensureCapacity(count + 1);

    elements[count++] = item;

    reheapUp(count - 1);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity) 
{
    if (minCapacity > capacity) 
    {
        capacity *= 2;

        T * newElements = new T[capacity];

        for (int i = 0; i < count; ++i)
            newElements[i] = elements[i];

        delete[] elements;
        elements = newElements;
    }
}

template<class T>
void Heap<T>::reheapUp(int position) 
{
    while (position > 0) 
    {
        int parent = (position - 1) / 2;

        if (elements[position] > elements[parent]) 
        {
            swap(elements[position], elements[parent]);
            position = parent;
        }
        else break;
    }
}