class Point
{
    private:
        double x, y;

    public:
        Point()
        {
            x = y = 0;
        }

        Point(double x, double y)
        {
            this->x = x;
            this->y = y;
        }

        void setX(double x)
        {
            this->x = x;
        }

        void setY(double y)
        {
            this->y = y;
        }

        double getX() const
        {
            return this->x;
        }

        double getY() const
        {
            return this->y;
        }

        double distanceToPoint(const Point& pointA)
        {
            return sqrt(pow(pointA.getX() - x, 2) + pow(pointA.getY() - y, 2));
        }
};