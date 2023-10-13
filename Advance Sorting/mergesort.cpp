template <typename T>
void mergesort(T arr[], int left, int right)
{
    if (left == right) return;
    
    int mid = (left + right) / 2;
    
    mergesort (arr, left, mid);
    mergesort (arr, mid + 1, right);
    
    merge (arr, left, mid, right);
};