vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) 
{
    for (auto op : operations)
    {
        int L = op[0];
        int R = op[1];
        int X = op[2];
        
        for (int i = L; i <= R; i++)
            nums[i] += X;
    }
    return nums;
}