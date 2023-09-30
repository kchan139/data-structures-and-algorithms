int buyCar(int* nums, int length, int k) 
{
    sort (nums, nums + length);
    
    int count = 0;
    while (count < length)
    {
        if (nums[count] <= k)
            k -= nums[count++];
        else break;
    }
    return count;
}