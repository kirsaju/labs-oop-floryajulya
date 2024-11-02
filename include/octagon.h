#ifndef OCTAGON_H
#define OCTAGON_H

#include <iostream>
#include <fstream>
#include <math.h>
#include "point.h"
#include "figure.h"

class Octagon : public Figure {
    private:
        Point p1;
        Point p2;
        Point p3;
        Point p4;
        Point p5;
        Point p6;
        Point p7;
        Point p8;

    public:
        Octagon ();
        Octagon (Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8);
        Octagon (const Octagon &other);
        Octagon (Octagon &&other);
        Octagon& operator= (const Octagon &other);
        Octagon& operator= (Octagon &&other);

        Point Center() const override;

        explicit operator double() const override;

        bool operator==(const Figure &other) const override;

        void Print(std::ostream &os) const override;

        friend std::istream &operator>>(std::istream &is, Octagon &r);
};

#endif // OCTAGON_H