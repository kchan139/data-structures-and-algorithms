int findMax(int* arr, int length) 
{
    if (length == 1) 
        return arr[0];
    else 
    {
        int max = findMax(arr, length - 1);
        
        return (arr[length - 1] > max) ? 
                arr[length - 1] : max;
    }
}