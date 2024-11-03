#ifndef POINT_H
#define POINT_H

#include <concepts>

template<typename T>
concept Scalar = std::is_arithmetic_v<T>;

template<Scalar T>
class Point {
public:
    T x;
    T y;

    Point() : x(0), y(0) {}

    Point(T xVal, T yVal) : x(xVal), y(yVal) {}

    T getX() const;
    T getY() const;

    void setX(T xVal);
    void setY(T yVal);

    bool operator==(const Point<T>& other) const;

};



#endif