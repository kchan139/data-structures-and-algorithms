int mountainWithoutValley(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    stack<int> s;
    vector<int> mt(n, 0); // to store the resulting mountain array

    // Build the left side of the mountain
    for (int i = 0; i < n; ++i) {
        if (s.empty())
            mt[i] = nums[i]; // start the mountain
        else
            mt[i] = min(nums[i], mt[s.top()] + 1); // increment the mountain up, but stay under the bound of nums[i]

        s.push(i); // push current index onto stack
    }

    // Clear the stack to use it for the right side
    while (!s.empty()) s.pop();

    // Adjust the right side of the mountain (descending side)
    for (int i = n - 1; i >= 0; --i) {
        if (s.empty())
            mt[i] = min(mt[i], nums[i]); // adjust within bounds
        else
            mt[i] = min(mt[i], mt[s.top()] + 1); // ensure no valleys

        s.push(i); // push current index onto stack
    }

    // Calculate the maximum sum of mt
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += mt[i];

    return sum;
}
