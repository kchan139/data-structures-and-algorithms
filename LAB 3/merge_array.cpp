static void merge(T* left, T* middle, T* right){
    /*TODO*/
    int size1 = middle - left + 1;
    int size2 = right - middle;
    int i1 = 0, i2 = 0, k = 0;
    int* l = new int[size1];
    int* r = new int[size2];
    for(int i = 0; i < size1; i++)
        l[i] = left[i];
    
    for(int j = 0; j < size2; j++)
        r[j] = middle[j+1];
    
    while(i1 < size1 && i2 < size2)
    {
        if(l[i1] <= r[i2])
            left[k++] = l[i1++];
        else
            left[k++] = r[i2++];
    }

    while(i1 < size1)
        left[k++] = l[i1++];
    
    while(i1 < size2)
        left[k++] = r[i2++];
        
    Sorting::printArray(left, right);
}
static void mergeSort(T* start, T* end){
    /*TODO*/
    if (start < end) {
        T* middle = start + (end - start) / 2;
        
        mergeSort(start, middle);
        mergeSort(middle + 1, end);
        
        merge(start, middle, end);
    }
}