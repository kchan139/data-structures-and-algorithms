int interpolationSearch(int arr[], int left, int right, int x) 
{
    if (left <= right && x >= arr[left] && x <= arr[right]) 
    {
        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (x - arr[left]));

        cout << "We traverse on index: " << pos << endl;

        if (arr[pos] == x)
            return pos;
            
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, right, x);

        if (arr[pos] > x)
            return interpolationSearch(arr, left, pos - 1, x);
    }

    return -1;
}