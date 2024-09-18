int maxSum (int* nums,int& n,int& k, int index = 0, int sum = 0)
{
    int &Maxsum = -10e8;
    if(index < n)
    {
        int Max = -10e8;
        int m = -10e8;
        for (int i = 0; i < k; i++)
        {
            if(index + i > n) return;
            Max = max (Max, nums[index + i]);

            if (Max * (i + 1) < m) 
                m = max (m, Max * (i + 1));
            else 
                Sum (nums, n, k, index + i + 1, sum + Max * (i+1));
            
        }
    }
    else if(index == n)
        Maxsum = max(Maxsum,sum);

    return Maxsum;
}