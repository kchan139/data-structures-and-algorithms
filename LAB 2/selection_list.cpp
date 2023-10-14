template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    int n = end - start;
    
    for(int i = 0; i < n - 1; i++)
    {
        int low = i;
        
        for (int j = n - 1; j > i; j--)
            if (start[j] <= start[low])
                low = j;
                
        swap (start[i], start[low]);
        
        printArray(start, end);
    }
}