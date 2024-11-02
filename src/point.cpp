#include "point.h"

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double xVal) {
    x = xVal;
}

void Point::setY(double yVal) {
    y = yVal;
}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}