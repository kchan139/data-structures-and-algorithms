int secondsToBeRotten(vector<vector<int>>& grid) 
{
    int rows = grid.size();
    if (rows == 0) return -1;

    int cols = grid[0].size();
    queue<pair<int, int>> rottenApples;

    for (int i = 0; i < rows; ++i) 
        for (int j = 0; j < cols; ++j) 
            if (grid[i][j] == 2) 
                rottenApples.push({i, j});
            

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int time = 0;

    while (!rottenApples.empty())
    {
        int size = rottenApples.size();
        bool freshAppleRotten = false;

        for (int i = 0; i < size; ++i) 
        {
            int x = rottenApples.front().first;
            int y = rottenApples.front().second;
            rottenApples.pop();

            for (int k = 0; k < 4; ++k) 
            {
                int newX = x + dirs[k][0];
                int newY = y + dirs[k][1];

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) 
                {
                    grid[newX][newY] = 2;
                    rottenApples.push({newX, newY});
                    freshAppleRotten = true;
                }
            }
        }

        if (freshAppleRotten)
            time++;
    }

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (grid[i][j] == 1)
                return -1;

    return time;
}