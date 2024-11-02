#ifndef HEXAGON_H
#define HEXAGON_H

#include <iostream>
#include <fstream>
#include <math.h>
#include "point.h"
#include "figure.h"

class Hexagon : public Figure {
    private:
        Point p1;
        Point p2;
        Point p3;
        Point p4;
        Point p5;
        Point p6;

    public:
        Hexagon ();
        Hexagon (Point p1, Point p2, Point p3, Point p4, Point p5, Point p6);
        Hexagon (const Hexagon &other);
        Hexagon (Hexagon &&other);
        Hexagon& operator= (const Hexagon &other);
        Hexagon& operator= (Hexagon &&other);

        Point Center() const override;

        explicit operator double() const override;

        bool operator==(const Figure &other) const override;

        void Print(std::ostream &os) const override;

        friend std::istream &operator>>(std::istream &is, Hexagon &r);
};

#endif // HEXAGON_H