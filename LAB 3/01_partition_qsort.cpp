static T* Partition(T* start, T* end) 
{
    const T pivot = *start;
    T* j = end;
    T* i = start;
    do 
    {
        do i++; while(*i < pivot);
        do j--; while(*j > pivot);
        
        const T temp = *i;
        *i = *j;
        *j = temp;
        
    }
    while(i < j);
    
    T temp = *i;
    *i = *j;
    *j = temp;
    
    temp = *start;
    *start = *j;
    *j = temp;
    
    return j;
}

static void QuickSort(T* start, T* end) 
{
    if (start == end) return;
    T* pivotPos = Partition(start,end);
    cout << (pivotPos - start) << " ";
    
    QuickSort(start,pivotPos);
    QuickSort(pivotPos + 1,end);
}