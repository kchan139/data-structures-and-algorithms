template <typename T>
int binarysearch(T arr[], int n, T k) 
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) 
    {
        mid = low + (high - low) / 2;
        cout << mid << ",";

        if (arr[mid] == k)
            return mid;
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return high;
};