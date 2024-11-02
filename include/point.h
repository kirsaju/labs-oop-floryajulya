#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x;
    double y;
public:
    Point() : x(0), y(0) {}

    Point(double xVal, double yVal) : x(xVal), y(yVal) {}

    double getX() const;
    double getY() const;

    void setX(double xVal);
    void setY(double yVal);

    bool operator==(const Point& other) const;

};



#endif // POINT_H