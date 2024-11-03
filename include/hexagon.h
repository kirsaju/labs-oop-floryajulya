#ifndef HEXAGON_H
#define HEXAGON_H

#include <cmath>
#include "figure.h"
#include "point.h"
#include <iostream>

template<Scalar T>
class Hexagon : public Figure<T> {
private:
    Point<T> p1, p2, p3, p4, p5, p6;

public:
    Hexagon(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4, Point<T> p5, Point<T> p6);
    Point<T> Center() const override;
    explicit operator double() const override;
    bool operator==(const Figure<T>& other) const override;
    void Print(std::ostream& os) const override;
};

template<Scalar T>
Hexagon<T>::Hexagon(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4, Point<T> p5, Point<T> p6)
    : p1(p1), p2(p2), p3(p3), p4(p4), p5(p5), p6(p6) {}

template<Scalar T>
Point<T> Hexagon<T>::Center() const {
    return Point<T>((p1.x + p2.x + p3.x + p4.x + p5.x + p6.x) / 6,
                    (p1.y + p2.y + p3.y + p4.y + p5.y + p6.y) / 6);
}

template<Scalar T>
Hexagon<T>::operator double() const {
    double s1 = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    double s2 = sqrt(pow(p3.x - p2.x, 2) + pow(p3.y - p2.y, 2));
    double s3 = sqrt(pow(p4.x - p3.x, 2) + pow(p4.y - p3.y, 2));
    double s4 = sqrt(pow(p5.x - p4.x, 2) + pow(p5.y - p4.y, 2));
    double s5 = sqrt(pow(p6.x - p5.x, 2) + pow(p6.y - p5.y, 2));
    double s6 = sqrt(pow(p1.x - p6.x, 2) + pow(p1.y - p6.y, 2));
    
    double averageSide = (s1 + s2 + s3 + s4 + s5 + s6) / 6;
    return (3 * sqrt(3) / 2) * pow(averageSide, 2);
}

template<Scalar T>
bool Hexagon<T>::operator==(const Figure<T> &other) const {
    const Hexagon<T> *hexagon = dynamic_cast<const Hexagon<T>*>(&other);
    if (!hexagon) {
        return false;
    }
    return (p1.x == hexagon->p1.x && p1.y == hexagon->p1.y &&
            p2.x == hexagon->p2.x && p2.y == hexagon->p2.y &&
            p3.x == hexagon->p3.x && p3.y == hexagon->p3.y &&
            p4.x == hexagon->p4.x && p4.y == hexagon->p4.y &&
            p5.x == hexagon->p5.x && p5.y == hexagon->p5.y &&
            p6.x == hexagon->p6.x && p6.y == hexagon->p6.y);
}

template<Scalar T>
void Hexagon<T>::Print(std::ostream& os) const {
    os << "Hexagon: (" << p1.x << ", " << p1.y << "), "
       << "(" << p2.x << ", " << p2.y << "), "
       << "(" << p3.x << ", " << p3.y << "), "
       << "(" << p4.x << ", " << p4.y << "), "
       << "(" << p5.x << ", " << p5.y << "), "
       << "(" << p6.x << ", " << p6.y << ")";
}

#endif
