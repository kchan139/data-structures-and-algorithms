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

class Circle
{
    private:
        Point center;
        double radius;

    public:
        Circle()
        {
            center.setX(0);
            center.setY(0);
            radius = 0;
        }

        Circle(Point center, double radius)
        {
            this->center = center;
            this->radius = radius;
        }

        Circle(const Circle &circle)
        {
            this->center = circle.getCenter();
            this->radius = circle.getRadius();
        }
        
        void setCenter(Point point)
        {
            this->center = point;
        }

        void setRadius(double radius)
        {
            this->radius = radius;
        }

        Point getCenter() const
        {
            return this->center;
        }

        double getRadius() const
        {
            return this->radius;
        }
        
        void printCircle()
        {
            printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
        }
};