double calculateDistance(const Point& p1, const Point& p2) 
{
    return sqrt (pow (p1.x - p2.x, 2) + pow (p1.y - p2.y, 2));
}

void closestKPoints(Point points[], int n, Point& des_point, int k) 
{
    vector<pair<double, Point>> distances;

    for (int i = 0; i < n; ++i) 
    {
        double distance = calculateDistance(points[i], des_point);
        distances.push_back({distance, points[i]});
    }
    
    for (int i = 0; i < n - 1; ++i) 
        for (int j = i + 1; j < n; ++j)
            if (distances[i].first > distances[j].first)
                swap (distances[i], distances[j]);

    for (int i = 0; i < k && i < n; ++i) 
    {
        distances[i].second.display();
        cout << endl;
    }
}