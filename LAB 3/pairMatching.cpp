int pairMatching(vector<int>& nums, int target) {
    unordered_map<int, int> freq;
    for (int num : nums)
        freq[num]++;
    
    int pairCount = 0;
    
    for (auto it = freq.begin(); it != freq.end(); it++) {
        int currentNum = it->first;
        int complement = target - currentNum;
        
        if (currentNum == complement) 
            pairCount += freq[currentNum] / 2;
        
        else if (currentNum < complement) {
            if (freq.find(complement) != freq.end())
                pairCount += min(freq[currentNum], freq[complement]);
        }
    }
    
    return pairCount;
}