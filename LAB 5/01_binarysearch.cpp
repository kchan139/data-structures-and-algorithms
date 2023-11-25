int binarySearch(int arr[], int left, int right, int x)
{
    if (left <= right)
    {
        int index = left + (right - left) / 2;
        cout << "We traverse on index: " << index << endl;
        
        if (arr[index] == x) return index;
        
        if (arr[index] < x) return binarySearch (arr, index + 1, right, x);
        
        return binarySearch (arr, left, index - 1, x);
    }
    
    return -1;
}