#ifndef FIGURE_H
#define FIGURE_H

#include <utility>
#include <stdexcept>
#include "point.h"

template<Scalar T>
class Figure {
public:
    virtual ~Figure() noexcept = default;

    virtual Point<T> Center() const = 0;

    virtual explicit operator double() const = 0;

    virtual bool operator==(const Figure<T> &other) const = 0;

    virtual void Print(std::ostream &os) const = 0;

    template<Scalar S>
    friend std::ostream &operator<<(std::ostream &os, const Figure<S> &figure);
};

#endif 
