#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"
#include "point.h"
#include <iostream>
#include <cmath>

template<Scalar T>
class Octagon : public Figure<T> {
private:
    Point<T> p1, p2, p3, p4, p5, p6, p7, p8;

public:
    Octagon(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4, 
            Point<T> p5, Point<T> p6, Point<T> p7, Point<T> p8);
    Point<T> Center() const override;
    explicit operator double() const override;
    bool operator==(const Figure<T>& other) const override;
    void Print(std::ostream& os) const override;
};

template<Scalar T>
Octagon<T>::Octagon(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4, 
                    Point<T> p5, Point<T> p6, Point<T> p7, Point<T> p8)
    : p1(p1), p2(p2), p3(p3), p4(p4), p5(p5), p6(p6), p7(p7), p8(p8) {}

template<Scalar T>
Point<T> Octagon<T>::Center() const {
    return Point<T>((p1.x + p2.x + p3.x + p4.x + p5.x + p6.x + p7.x + p8.x) / 8,
                    (p1.y + p2.y + p3.y + p4.y + p5.y + p6.y + p7.y + p8.y) / 8);
}

template<Scalar T>
Octagon<T>::operator double() const {
    double s1 = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    double s2 = sqrt(pow(p3.x - p2.x, 2) + pow(p3.y - p2.y, 2));
    double s3 = sqrt(pow(p4.x - p3.x, 2) + pow(p4.y - p3.y, 2));
    double s4 = sqrt(pow(p5.x - p4.x, 2) + pow(p5.y - p4.y, 2));
    double s5 = sqrt(pow(p6.x - p5.x, 2) + pow(p6.y - p5.y, 2));
    double s6 = sqrt(pow(p7.x - p6.x, 2) + pow(p7.y - p6.y, 2));
    double s7 = sqrt(pow(p8.x - p7.x, 2) + pow(p8.y - p7.y, 2));
    double s8 = sqrt(pow(p1.x - p8.x, 2) + pow(p1.y - p8.y, 2));
    
    double averageSide = (s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) / 8;
    return 2 * (1 + sqrt(2)) * pow(averageSide, 2);
}

template<Scalar T>
bool Octagon<T>::operator==(const Figure<T> &other) const {
    const Octagon<T> *octagon = dynamic_cast<const Octagon<T>*>(&other);
    if (!octagon) {
        return false; 
    }
    return (p1.x == octagon->p1.x && p1.y == octagon->p1.y &&
            p2.x == octagon->p2.x && p2.y == octagon->p2.y &&
            p3.x == octagon->p3.x && p3.y == octagon->p3.y &&
            p4.x == octagon->p4.x && p4.y == octagon->p4.y &&
            p5.x == octagon->p5.x && p5.y == octagon->p5.y &&
            p6.x == octagon->p6.x && p6.y == octagon->p6.y &&
            p7.x == octagon->p7.x && p7.y == octagon->p7.y &&
            p8.x == octagon->p8.x && p8.y == octagon->p8.y);
}
template<Scalar T>
void Octagon<T>::Print(std::ostream& os) const {
    os << "Octagon: (" << p1.x << ", " << p1.y << "), "
       << "(" << p2.x << ", " << p2.y << "), "
       << "(" << p3.x << ", " << p3.y << "), "
       << "(" << p4.x << ", " << p4.y << "), "
       << "(" << p5.x << ", " << p5.y << "), "
       << "(" << p6.x << ", " << p6.y << "), "
       << "(" << p7.x << ", " << p7.y << "), "
       << "(" << p8.x << ", " << p8.y << ")";
}

#endif
