static void merge(T* start, T* middle, T* end) 
{
    // TODO
    int size1 = middle - start + 1;
    int size2 = end - middle;
    int i1 = 0, i2 = 0, k = 0;
    int* l = new int[size1];
    int* r = new int[size2];
    for(int i = 0; i < size1; i++)
        l[i] = start[i];
    
    for(int j = 0; j < size2; j++)
        r[j] = middle[j+1];
    
    while(i1 < size1 && i2 < size2)
    {
        if(l[i1] <= r[i2])
            start[k++] = l[i1++];
        else
            start[k++] = r[i2++];
    }

    while(i1 < size1)
        start[k++] = l[i1++];
    
    while(i1 < size2)
        start[k++] = r[i2++];
}

static void InsertionSort(T* start, T* end) 
{
    // TODO
    int n = end - start;
    for(int i = 1; i < n; i++)
        for(int j = i; j > 0 && start[j] < start[j - 1]; j--)
            swap (start[j], start[j - 1]);
}

static void TimSort(T* start, T* end, int min_size) 
{
    // TODO
    // You must print out the array after using insertion sort and everytime calling method merge.
    int n = end - start;
    T *s = start, *e = end;
    for(int i = 0; i < n; i += min_size)
    {
        if (i + min_size <= n)
        {
            InsertionSort(s, s + min_size);
            s += min_size;
        }
        else InsertionSort(s, e);
    }
    cout << "Insertion Sort: ";
    printArray (start, end);

    int count = 0;
    for (int gap = min_size; gap < n; gap *= 2)
    {
		s = start;
		for (int j = 0; j < n; j += 2 * gap)
        {
			T* mid = s + gap - 1;
			if (j + gap - 1 >= n) 
                mid = end - 1;
			if (j + 2 * gap - 1 < n)
				e = s + 2 * gap - 1;
			else e = end - 1;

			merge(s, mid, e);
			cout << "Merge " << ++count << ": ";
			printArray(start,end);
			s += 2 * gap;
		}
	}
}