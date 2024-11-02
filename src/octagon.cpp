#include "octagon.h"
#include <cmath>

Octagon::Octagon() : p1(), p2(), p3(), p4(), p5(), p6(), p7(), p8() {
}

Octagon::Octagon(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8)
    : p1(p1), p2(p2), p3(p3), p4(p4), p5(p5), p6(p6), p7(p7), p8(p8) {
}

Octagon::Octagon(const Octagon &other)
    : p1(other.p1), p2(other.p2), p3(other.p3), p4(other.p4),
      p5(other.p5), p6(other.p6), p7(other.p7), p8(other.p8) {}

Octagon::Octagon(Octagon &&other)
    : p1(std::move(other.p1)), p2(std::move(other.p2)), p3(std::move(other.p3)),
      p4(std::move(other.p4)), p5(std::move(other.p5)), p6(std::move(other.p6)),
      p7(std::move(other.p7)), p8(std::move(other.p8)) {}

Octagon& Octagon::operator=(const Octagon &other) {
    if (this == &other) return *this;
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    p4 = other.p4;
    p5 = other.p5;
    p6 = other.p6;
    p7 = other.p7;
    p8 = other.p8;
    return *this;
}

Octagon& Octagon::operator=(Octagon &&other) {
    if (this == &other) return *this;
    p1 = std::move(other.p1);
    p2 = std::move(other.p2);
    p3 = std::move(other.p3);
    p4 = std::move(other.p4);
    p5 = std::move(other.p5);
    p6 = std::move(other.p6);
    p7 = std::move(other.p7);
    p8 = std::move(other.p8);
    return *this;
}

Point Octagon::Center() const {
    double x = (p1.getX() + p2.getX() + p3.getX() + p4.getX() +
                p5.getX() + p6.getX() + p7.getX() + p8.getX()) / 8.0;
    double y = (p1.getY() + p2.getY() + p3.getY() + p4.getY() +
                p5.getY() + p6.getY() + p7.getY() + p8.getY()) / 8.0;
    return Point(x, y);
}

Octagon::operator double() const {
    double area = 0.0;
    const Point* points[] = { &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8 };
    for (int i = 0; i < 8; ++i) {
        const Point* current = points[i];
        const Point* next = points[(i + 1) % 8];
        area += (current->getX() * next->getY()) - (next->getX() * current->getY());
    }
    area = std::fabs(area) / 2.0;
    return area;
}

bool Octagon::operator==(const Figure &other) const {
    const Octagon* otherOct = dynamic_cast<const Octagon*>(&other);
    if (!otherOct) return false;
    return p1 == otherOct->p1 && p2 == otherOct->p2 && p3 == otherOct->p3 &&
           p4 == otherOct->p4 && p5 == otherOct->p5 && p6 == otherOct->p6 &&
           p7 == otherOct->p7 && p8 == otherOct->p8;
}

void Octagon::Print(std::ostream &os) const {
    os << "Octagon vertices:\n";
    os << "P1: (" << p1.getX() << ", " << p1.getY() << ")\n";
    os << "P2: (" << p2.getX() << ", " << p2.getY() << ")\n";
    os << "P3: (" << p3.getX() << ", " << p3.getY() << ")\n";
    os << "P4: (" << p4.getX() << ", " << p4.getY() << ")\n";
    os << "P5: (" << p5.getX() << ", " << p5.getY() << ")\n";
    os << "P6: (" << p6.getX() << ", " << p6.getY() << ")\n";
    os << "P7: (" << p7.getX() << ", " << p7.getY() << ")\n";
    os << "P8: (" << p8.getX() << ", " << p8.getY() << ")\n";
}

std::istream &operator>>(std::istream &is, Octagon &r) {
    Point points[8];
    for (int i = 0; i < 8; ++i) {
        double x, y;
        if (!(is >> x >> y)) {
            is.setstate(std::ios::failbit);
            return is;
        }
        points[i] = Point(x, y);
    }
    r = Octagon(points[0], points[1], points[2], points[3],
                points[4], points[5], points[6], points[7]);
    return is;
}
