int minimumAmplitude(vector<int>& nums, int k) 
{
    int n = nums.size();
    if (n <= k) return 0;
    
    vector<int> prefixMin(n, INT_MAX);
    vector<int> prefixMax(n, INT_MIN);
    vector<int> suffixMin(n, INT_MAX);
    vector<int> suffixMax(n, INT_MIN);

    prefixMin[0] = nums[0];
    prefixMax[0] = nums[0];
    for (int i = 1; i < n; ++i) 
    {
        prefixMin[i] = min(prefixMin[i - 1], nums[i]);
        prefixMax[i] = max(prefixMax[i - 1], nums[i]);
    }

    suffixMin[n - 1] = nums[n - 1];
    suffixMax[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) 
    {
        suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        suffixMax[i] = max(suffixMax[i + 1], nums[i]);
    }

    int minAmplitude = INT_MAX;

    for (int i = 0; i <= n - k; ++i) 
    {
        int leftMax = (i > 0) ? prefixMax[i - 1] : INT_MIN;
        int leftMin = (i > 0) ? prefixMin[i - 1] : INT_MAX;
        int rightMax = (i + k < n) ? suffixMax[i + k] : INT_MIN;
        int rightMin = (i + k < n) ? suffixMin[i + k] : INT_MAX;
        
        int currentMax = max(leftMax, rightMax);
        int currentMin = min(leftMin, rightMin);
        int currentAmplitude = currentMax - currentMin;

        minAmplitude = min(minAmplitude, currentAmplitude);
    }

    return minAmplitude;
}