#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include "point.h"
#include <cmath>
#include <iostream>
#include <cmath>

template<Scalar T>
class Triangle : public Figure<T> {
private:
    Point<T> p1, p2, p3;

public:
    Triangle(Point<T> p1, Point<T> p2, Point<T> p3);
    Point<T> Center() const override;
    explicit operator double() const override;
    bool operator==(const Figure<T>& other) const override;
    void Print(std::ostream& os) const override;
};

template<Scalar T>
Triangle<T>::Triangle(Point<T> p1, Point<T> p2, Point<T> p3)
    : p1(p1), p2(p2), p3(p3) {}

template<Scalar T>
Point<T> Triangle<T>::Center() const {
    return Point<T>((p1.x + p2.x + p3.x) / 3,
                    (p1.y + p2.y + p3.y) / 3);
}

template<Scalar T>
Triangle<T>::operator double() const {
    double base = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    double height = abs((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y)) / base;
    return 0.5 * base * height;
}

template<Scalar T>
bool Triangle<T>::operator==(const Figure<T>& other) const {
    const Triangle<T> *triangle = dynamic_cast<const Triangle<T>*>(&other);
    if (!triangle) {
        return false;
    }
    return (p1.x == triangle->p1.x && p1.y == triangle->p1.y &&
            p2.x == triangle->p2.x && p2.y == triangle->p2.y &&
            p3.x == triangle->p3.x && p3.y == triangle->p3.y);
}

template<Scalar T>
void Triangle<T>::Print(std::ostream& os) const {
    os << "Triangle: (" << p1.x << ", " << p1.y << "), "
       << "(" << p2.x << ", " << p2.y << "), "
       << "(" << p3.x << ", " << p3.y << ")";
}

#endif
