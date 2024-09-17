int maxSum (int* nums, int n, int k) 
{
    int max = 0;
    
    for (int i = 0; i + k <= n; i++) 
    {
        int tmp = 0;
        
        for (int j = i; j < i + k; j++)
            tmp += nums[j];
            
        if (tmp > max)
            max = tmp;
    }

    return max;
}