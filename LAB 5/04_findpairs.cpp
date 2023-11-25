bool checkAnswer(int a, int b, int c, int d) 
{
    return (a + b == c + d) &&
           (a != b) && (a != c) && (a != d) && 
           (b != c) && (b != d) && (c != d);
}

bool findPairs(int arr[], int n, pair<int, int>& pair1, pair<int, int>& pair2) 
{
    map<int, pair<int, int>> sumMap;

    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            int sum = arr[i] + arr[j];

            if (sumMap.find(sum) != sumMap.end()) 
            {
                pair1 = {sumMap[sum].first, sumMap[sum].second};
                pair2 = {arr[i], arr[j]};

                if (checkAnswer(pair1.first, pair1.second, pair2.first, pair2.second))
                    return true;
            }

            sumMap[sum] = {arr[i], arr[j]};
        }
    }

    return false;
}