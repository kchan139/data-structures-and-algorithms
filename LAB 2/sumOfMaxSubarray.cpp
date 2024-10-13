int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    int n = nums.size();
    if (n == 0 || k > n) return 0;

    deque<int> dq;
    int sum = 0;

    for (int i = 0; i < k; ++i) {
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
    }

    for (int i = k; i < n; ++i) {
        sum += nums[dq.front()];

        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    sum += nums[dq.front()];

    return sum;
}