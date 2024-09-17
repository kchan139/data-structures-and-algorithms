class Point
{
private:
    double x, y;

public:
    Point() : x(0), y(0) {}

    Point(double x, double y) : x(x), y(y) {}

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    double getX() const { return x; }
    double getY() const { return y; }

    double distanceToPoint(const Point& point) const
    {
        return sqrt(pow(point.getX() - x, 2) + pow(point.getY() - y, 2));
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
    
    void operator=(const Circle &circle)
    {
        /*  
         * STUDENT ANSWER
         */
        if (this == &circle) // self-assignment check
            return;
    
        center = circle.center; // Copy center
        radius = circle.radius;
    }

    bool operator==(const Circle &circle)
    {
        /*  
         * STUDENT ANSWER
         */
        return (center.getX() == circle.center.getX() &&
                center.getY() == circle.center.getY() &&
                       radius == circle.radius);
    }

    friend istream& operator >> (istream &in, Circle &circle)
    {
        /*  
         * STUDENT ANSWER
         */
        double x, y, r;
        in >> x >> y >> r;
        circle.center.setX(x);
        circle.center.setY(y);
        circle.radius = r;
        return in;
    }

    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};