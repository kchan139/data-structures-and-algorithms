int leastAfter(vector<int>& nums, int k) 
{
    priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
    
    for (int i = 0; i < k; i++)
    {
        int smallest = minHeap.top();
        minHeap.pop();
        
        minHeap.push(smallest * 2);
    }
    
    return minHeap.top();
}