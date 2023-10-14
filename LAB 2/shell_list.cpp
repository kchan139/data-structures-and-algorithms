static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
    // useful function
}

static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) 
{
    int cnt = end - start;
    
    for (int i = num_phases - 1; i >= 0; i--)
    {
        int incr = num_segment_list[i];
        
        for (int j = 0; j < cnt - incr; j++)
            for (int k = 0; k < cnt - incr; k++)
                for (int m = k; m < cnt - incr && start[m] > start[m + incr]; m++)
                    swap (start[m], start[m + incr]);
    
        cout << incr << " segments: ";
        printArray(start, end);
    }
}