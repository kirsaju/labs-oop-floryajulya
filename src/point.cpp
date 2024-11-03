#include "point.h"

template<Scalar T>
T Point<T>::getX() const {
    return x;
}

template<Scalar T>
T Point<T>::getY() const {
    return y;
}

template<Scalar T>
void Point<T>::setX(T xVal) {
    x = xVal;
}

template<Scalar T>
void Point<T>::setY(T yVal) {
    y = yVal;
}

template<Scalar T>
bool Point<T>::operator==(const Point<T>& other) const {
    return x == other.x && y == other.y;
}