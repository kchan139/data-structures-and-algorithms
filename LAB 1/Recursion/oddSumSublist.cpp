int oddSumSublist(vector<int>& nums, int m) {
    int oddCount = 0, evenCount = 1;
    int currentSum = 0;
    int result = 0;

    for (int num : nums) 
    {
        currentSum += num;
        
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
    }
    
    return result;
}