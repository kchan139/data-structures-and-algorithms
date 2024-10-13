bool tripleIndexSLM(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return false;

    stack<int> s;
    int secondMax = INT32_MIN;

    for (int i = n - 1; i >= 0; --i) {
        if (nums[i] < secondMax)
            return true;

        while (!s.empty() && nums[i] > s.top()) {
            secondMax = s.top();
            s.pop();
        }

        s.push(nums[i]);
    }
    
    return false;
}
