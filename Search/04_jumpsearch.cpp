template <typename T>
bool jumpsearch(T arr[], int n, T k, int j) 
{
    int prev = 0;
    int i = 0;

    for (; i < n; i += j) 
    {
        cout << arr[i] << ",";
        // cout << "PREV: " << prev << endl;
        // cout << "I: " << i << endl;

        if (arr[i] == k)
            return true;

        if (arr[i] > k)
            break;
            
        prev = i;
    }
    
    if (arr[prev] > k) return false;

    for (int m = prev + 1; m < min (i + j, n); m++) 
    {
        cout << arr[m] << ",";
        
        if (arr[m] == k)
            return true;

        if (arr[m] > k)
            return false;
    }

    return false;
}