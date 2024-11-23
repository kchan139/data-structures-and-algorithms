int uglyNumberIndex(int n) {
    // STUDENT ANSWER
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    set<long long> seen;
    
    minHeap.push(1);
    seen.insert(1);
    
    long long current = 1;
    
    for (int i = 0; i <= n; i++) {
        current = minHeap.top();
        minHeap.pop();
        
        for (int prime : primes) {
            long long next = current * prime;
            if (seen.find(next) == seen.end()) {
                minHeap.push(next);
                seen.insert(next);
            }
        }
    }
    
    return (int)current;
}