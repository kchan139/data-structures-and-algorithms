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

    bool containsPoint(const Point point)
    {
        /*  
         * STUDENT ANSWER 
         * TODO: check if a given point is entirely within the circle (does not count if the point lies on the circle).  
                 If contain, return true.
         */
        return point.distanceToPoint (center) < radius;
    }

    bool containsTriangle(const Point pointA, const Point pointB, const Point pointC)
    {
        /*  
         * STUDENT ANSWER   
         * TODO: check if a given triangle ABC (A, B, C are not on the same line) is entirely within the circle (does not count if any point of the triangle lies on the circle).  
                 If contain, return true.
         */
        return containsPoint(pointA) 
            && containsPoint(pointB) 
            && containsPoint(pointC);
    }
};