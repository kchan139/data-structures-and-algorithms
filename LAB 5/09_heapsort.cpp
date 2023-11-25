static void heapify(T* arr, long size, long i) 
{
    long largest = i;
    long left    = 2 * i + 1;
    long right  = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}


static void heapSort(T * start, T * end) 
{
    long size = end - start;
    
    for (long i = size / 2 - 1; i >= 0; i--)
        heapify(start, size, i);

    for (long i = size - 1; i > 0; i--) 
    {
        swap(start[0], start[i]);
        heapify(start, i, 0);
    }

    Sorting<T>::printArray(start, end);
}