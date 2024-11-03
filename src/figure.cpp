#include "figure.h"

template<Scalar T>
std::ostream &operator<<(std::ostream &os, const Figure<T> &figure) {
    figure.Print(os);
    return os;
}