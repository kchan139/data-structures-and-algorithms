template <typename T>
bool binarysearch (T arr[], int left, int right, T k)
{
    if (left > right) return false;
    
    int mid = left + (right - left)/2;
    
    cout << arr[mid] << ",";
    
    if (arr[mid] == k) return true;
    
    if (arr[mid] > k) return binarysearch (arr, left, mid - 1, k);
    
    return binarysearch (arr, mid + 1, right, k);
};