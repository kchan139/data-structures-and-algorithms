int jumpSearch (int arr[], int x, int n) 
{
    int prev = 0;
    int i = 0;
    int j = sqrt (n);

    for (; i < n; i += j) 
    {
        cout << i << " ";

        if (arr[i] == x)
            return i;
            
        if (arr[i] > x)
            break;
            
        prev = i;
    }
    
    if (arr[prev] > x) return -1;

    for (int m = prev + 1; m < min (i + j, n) + 1; m++) 
    {
        if (arr[m] > x)
            return -1;
            
        cout << m << " ";
        
        if (arr[m] == x)
            return m;
    }

    return -1;
}