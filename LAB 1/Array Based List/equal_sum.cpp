int equalSumIndex(vector<int>& nums) 
{
    // STUDENT ANSWER
    int size = nums.size();
    int left = 0, right = 0;
    
    for (int num : nums)
        right += num;
        
    for (int i = 0; i < size; i++)
    {
        right -= nums[i];
        
        if (left == right)
            return i;
        
        left += nums[i];
    }
    return -1;
}