#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <fstream>
#include <math.h>
#include <stdexcept>
#include "point.h"
#include "figure.h"

class Triangle : public Figure {
    private:
        Point p1;
        Point p2;
        Point p3;

    public:
        Triangle ();
        Triangle (Point p1, Point p2, Point p3);
        Triangle (const Triangle &other);
        Triangle (Triangle &&other);
        Triangle& operator= (const Triangle &other);
        Triangle& operator= (Triangle &&other);        

        Point Center() const override;

        explicit operator double() const override;

        bool operator==(const Figure &other) const override;

        void Print(std::ostream &os) const override;

        friend std::istream &operator>>(std::istream &is, Triangle &r);
};

#endif // TRIANGLE_H