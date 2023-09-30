bool sameFirstLetter(const string& word1, const string& word2) 
{
    return word1[0] == word2[0];
}

int longestSublist(vector<string>& words) 
{
    int longestLen = 0,
        currLen = 1;
    int wsize = words.size();
    if (wsize == 0) return 0;

    for (int i = 1; i < wsize; i++) 
    {
        if (sameFirstLetter(words[i - 1], words[i]))
            currLen++;  
        else 
        {
            if (currLen > longestLen)
                longestLen = currLen;
            currLen = 1; 
        }
    }
    
    return max (currLen, longestLen);
}
