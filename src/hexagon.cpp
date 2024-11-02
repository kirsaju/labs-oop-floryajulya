#include "hexagon.h"
#include <cmath>

Hexagon::Hexagon() : p1(), p2(), p3(), p4(), p5(), p6() {
}

Hexagon::Hexagon(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6)
    : p1(p1), p2(p2), p3(p3), p4(p4), p5(p5), p6(p6) {
}

Hexagon::Hexagon(const Hexagon &other)
    : p1(other.p1), p2(other.p2), p3(other.p3), p4(other.p4), p5(other.p5), p6(other.p6) {}

Hexagon::Hexagon(Hexagon &&other)
    : p1(std::move(other.p1)), p2(std::move(other.p2)), p3(std::move(other.p3)),
      p4(std::move(other.p4)), p5(std::move(other.p5)), p6(std::move(other.p6)) {}

Hexagon& Hexagon::operator=(const Hexagon &other) {
    if (this == &other) return *this;
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    p4 = other.p4;
    p5 = other.p5;
    p6 = other.p6;
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon &&other) {
    if (this == &other) return *this;
    p1 = std::move(other.p1);
    p2 = std::move(other.p2);
    p3 = std::move(other.p3);
    p4 = std::move(other.p4);
    p5 = std::move(other.p5);
    p6 = std::move(other.p6);
    return *this;
}

Point Hexagon::Center() const {
    double x = (p1.getX() + p2.getX() + p3.getX() + p4.getX() + p5.getX() + p6.getX()) / 6.0;
    double y = (p1.getY() + p2.getY() + p3.getY() + p4.getY() + p5.getY() + p6.getY()) / 6.0;
    return Point(x, y);
}

Hexagon::operator double() const {
    double area = 0.0;
    const Point* points[] = { &p1, &p2, &p3, &p4, &p5, &p6 };
    for (int i = 0; i < 6; ++i) {
        const Point* current = points[i];
        const Point* next = points[(i + 1) % 6];
        area += (current->getX() * next->getY()) - (next->getX() * current->getY());
    }
    area = std::fabs(area) / 2.0;
    return area;
}

bool Hexagon::operator==(const Figure &other) const {
    const Hexagon* otherHex = dynamic_cast<const Hexagon*>(&other);
    if (!otherHex) return false;
    return p1 == otherHex->p1 && p2 == otherHex->p2 && p3 == otherHex->p3 &&
           p4 == otherHex->p4 && p5 == otherHex->p5 && p6 == otherHex->p6;
}

void Hexagon::Print(std::ostream &os) const {
    os << "Hexagon vertices:\n";
    os << "P1: (" << p1.getX() << ", " << p1.getY() << ")\n";
    os << "P2: (" << p2.getX() << ", " << p2.getY() << ")\n";
    os << "P3: (" << p3.getX() << ", " << p3.getY() << ")\n";
    os << "P4: (" << p4.getX() << ", " << p4.getY() << ")\n";
    os << "P5: (" << p5.getX() << ", " << p5.getY() << ")\n";
    os << "P6: (" << p6.getX() << ", " << p6.getY() << ")\n";
}

std::istream &operator>>(std::istream &is, Hexagon &r) {
    Point points[6];
    for (int i = 0; i < 6; ++i) {
        double x, y;
        if (!(is >> x >> y)) {
            is.setstate(std::ios::failbit);
            return is;
        }
        points[i] = Point(x, y);
    }
    r = Hexagon(points[0], points[1], points[2], points[3], points[4], points[5]);
    return is;
}
