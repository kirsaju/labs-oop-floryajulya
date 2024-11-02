#ifndef FIGURE_H
#define FIGURE_H

#include <utility>
#include <stdexcept>
#include "point.h"

class Figure {
public:
    virtual ~Figure() noexcept = default;

    virtual Point Center() const = 0;

    virtual explicit operator double() const = 0;

    virtual bool operator==(const Figure &other) const = 0;

    virtual void Print(std::ostream &os) const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Figure &figure);
};

#endif //FIGURE_H
