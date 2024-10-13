int sumOfMinSubarray(vector<int>& nums) {
    int n = nums.size();
    const int MOD = 10000;
    stack<int> s;
    vector<int> left(n), right(n);
    
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && nums[s.top()] > nums[i])
            s.pop();
        
        left[i] = s.empty() ? i + 1 : i - s.top();
        s.push(i);
    }

    while (!s.empty()) s.pop();

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && nums[s.top()] >= nums[i]) 
            s.pop();
        
        right[i] = s.empty() ? n - i : s.top() - i;
        s.push(i);
    }

    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum = (sum + nums[i] * left[i] * right[i]) % MOD;

    return sum;
}
