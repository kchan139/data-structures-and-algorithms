int maxSum(int* nums, int n, int k) {
   int dp[n] = {0};
    
    for (int i = 0; i < n; ++i) {
        int maxElement = nums[i];
        
        for (int j = 1; j <= k && i - j + 1 >= 0; ++j) {
            maxElement = max(maxElement, nums[i - j + 1]);
            int currentS = maxElement * j;
            
            if (i - j >= 0) {
                dp[i] = max(dp[i], dp[i - j] + currentS);
            } else {
                dp[i] = max(dp[i], currentS);
            }
        }
    }

    return dp[n - 1];
}