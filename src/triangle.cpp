#include "triangle.h"
#include <cmath>

Triangle::Triangle() : p1(), p2(), p3() {
}

Triangle::Triangle(Point p1, Point p2, Point p3)
    : p1(p1), p2(p2), p3(p3) {
}

Triangle::Triangle(const Triangle &other)
    : p1(other.p1), p2(other.p2), p3(other.p3) {}

Triangle::Triangle(Triangle &&other)
    : p1(std::move(other.p1)), p2(std::move(other.p2)), p3(std::move(other.p3)) {}

Triangle& Triangle::operator=(const Triangle &other) {
    if (this == &other) return *this;
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    return *this;
}

Triangle& Triangle::operator=(Triangle &&other) {
    if (this == &other) return *this;
    p1 = std::move(other.p1);
    p2 = std::move(other.p2);
    p3 = std::move(other.p3);
    return *this;
}

Point Triangle::Center() const {
    double x = (p1.getX() + p2.getX() + p3.getX()) / 3.0;
    double y = (p1.getY() + p2.getY() + p3.getY()) / 3.0;
    return Point(x, y);
}

Triangle::operator double() const {
    double area = 0.5 * std::fabs(
        p1.getX() * (p2.getY() - p3.getY()) +
        p2.getX() * (p3.getY() - p1.getY()) +
        p3.getX() * (p1.getY() - p2.getY())
    );
    return area;
}

bool Triangle::operator==(const Figure &other) const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    if (!otherTriangle) return false;
    return p1 == otherTriangle->p1 && p2 == otherTriangle->p2 && p3 == otherTriangle->p3;
}

void Triangle::Print(std::ostream &os) const {
    os << "Triangle vertices:\n";
    os << "P1: (" << p1.getX() << ", " << p1.getY() << ")\n";
    os << "P2: (" << p2.getX() << ", " << p2.getY() << ")\n";
    os << "P3: (" << p3.getX() << ", " << p3.getY() << ")\n";
}

std::istream &operator>>(std::istream &is, Triangle &r) {
    double x1, y1, x2, y2, x3, y3;
    if (!(is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
        is.setstate(std::ios::failbit);
        return is;
    }
    r = Triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
    return is;
}
