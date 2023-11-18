template <typename T>
bool dictionarySearch(T arr[], int left, int right, T k) 
{
    while (left <= right && k >= arr[left] && k <= arr[right]) 
    {
        int pos = round
                  ( left + 
                  ( ( (double)(right - left) / (arr[right] - arr[left]) ) * 
                  ( k - arr[left]) ) );

        cout << arr[pos] << ",";

        if (arr[pos] == k)
            return true;

        if (arr[pos] < k)
            left = pos + 1;
        else right = pos - 1;
    }
    return false;
}
