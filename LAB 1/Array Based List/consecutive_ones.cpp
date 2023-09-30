bool consecutiveOnes(vector<int>& nums) 
{
    if (nums.empty()) return true;
    
    int size = nums.size();
    
    bool one = false,
         space = false;
    
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == 1)
        {
            if (space) return false;
            one = true;
        }
        else if (one) space = true;
    }
    return true;
}