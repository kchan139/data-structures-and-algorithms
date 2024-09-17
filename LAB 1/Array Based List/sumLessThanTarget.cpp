int sumLessThanTarget(vector<int>& nums, int target) 
{
    int left = 0;
    int right = nums.size() - 1;
    int maxSum = INT_MIN;

    while (left < right) 
    {
        int currentSum = nums[left] + nums[right];
        if (currentSum < target) 
        {
            maxSum = max(maxSum, currentSum);
            ++left;
        }
        else --right;
    }

    return maxSum;
}