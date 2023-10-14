#include <vector>
int baseballScore(string ops)
{
    int n = ops.size();
    vector<int> arr;
    int sum = 0, j = 0;
    
    for (int i = 0; i < n; ++i)
    {
        if (isdigit(ops[i]))
        {
            arr.push_back(ops[i] - 48);
            ++j;
        }
        else if (ops[i] == 'C')
        {
            arr.pop_back();
            --j;
        }
        else if (ops[i] == 'D')
        {
            arr.push_back(arr[j - 1] * 2);
            ++j;
        }
        else
        {
            arr.push_back(arr[j - 2] + arr[j - 1]);
            ++j;
        }
    }
    
    for (unsigned int i = 0 ; i < arr.size(); ++i)
        sum += arr[i];
    
    return sum;
}