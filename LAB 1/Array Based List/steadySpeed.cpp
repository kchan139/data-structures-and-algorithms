int steadySpeed(vector<int>& positions) 
{
    int len = positions.size();

    vector<int> v(len - 1,0);
    for(int i = 1; i < len; i++)
        v[i-1] = abs(positions[i] - positions[i-1]);

    int tmp   = v[0];
    int count = 1;
    int Max   = 0;

    for (int i = 1; i < len - 1; i++)
    {
        if(tmp == v[i]) 
            count ++;
        else 
        {
            Max = max(Max, count);
            count = 1;
            tmp = v[i];
        }
    }
    return max(Max, count) + 1;
}