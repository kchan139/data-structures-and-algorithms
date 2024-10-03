int helper(const vector<int>& nums, int index, int oddCount, int evenCount, int currentSum, int result, int m) 
{
    if (index == nums.size())
        return result;

    currentSum += nums[index];

    if (currentSum % 2 != 0) 
    {
        result = (result + evenCount) % m;
        oddCount++;
    } 
    else 
    {
        result = (result + oddCount) % m;
        evenCount++;
    }

    return helper(nums, index + 1, oddCount, evenCount, currentSum, result, m);
}

int oddSumSublist(vector<int>& nums, int m) 
{
    return helper(nums, 0, 0, 1, 0, 0, m);
}