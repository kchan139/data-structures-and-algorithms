int reduceSum(vector<int>& nums) {
    // STUDENT ANSWER
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums)
        minHeap.push(num);

    int totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        int currentCost = first + second;
        totalCost += currentCost;

        minHeap.push(currentCost);
    }

    return totalCost;
}