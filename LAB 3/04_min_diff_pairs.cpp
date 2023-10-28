string minDiffPairs(int* arr, int n) 
{
    sort (arr, arr + n);
    int minDiff = INT32_MAX;
    
    for (int i = 1; i < n; ++i) 
    {
        int diff = arr[i] - arr[i - 1];
        minDiff = min (minDiff, diff);
    }

    bool found = false;
    for (int i = 1; i < n; ++i) 
    {
        int diff = arr[i] - arr[i - 1];
        if (diff == minDiff) 
        {
            if (found) cout << ", ";

            cout << "(" << arr[i - 1] << ", " << arr[i] << ")";
            found = true;
        }
    }
    
    cout << endl;

    return "";
}