#ifndef ARRAY_H
#define ARRAY_H

#include "figure.h"
#include <memory>
#include <stdexcept>

template<typename T>
class FigureArray {
public:
    FigureArray();
    ~FigureArray();
    void Add(std::unique_ptr<Figure<T>> figure);
    void Remove(size_t index);
    Figure<T>* Get(size_t index) const;
    size_t Size() const;
    double TotalArea() const;

private:
    void Resize(size_t newCapacity);
    std::unique_ptr<std::unique_ptr<Figure<T>>[]> elems;
    size_t capacity;
    size_t count;
};

template<typename T>
FigureArray<T>::FigureArray() : elems(nullptr), capacity(0), count(0) {}

template<typename T>
FigureArray<T>::~FigureArray() {}

template<typename T>
void FigureArray<T>::Add(std::unique_ptr<Figure<T>> figure) {
    if (count == capacity) {
        Resize(capacity == 0 ? 1 : capacity * 2);
    }
    elems[count++] = std::move(figure);
}

template<typename T>
void FigureArray<T>::Remove(size_t index) {
    if (index >= count) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < count - 1; ++i) {
        elems[i] = std::move(elems[i + 1]);
    }
    --count;
}

template<typename T>
Figure<T>* FigureArray<T>::Get(size_t index) const {
    if (index >= count) {
        throw std::out_of_range("Index out of range");
    }
    return elems[index].get();
}

template<typename T>
size_t FigureArray<T>::Size() const {
    return count;
}

template<typename T>
void FigureArray<T>::Resize(size_t newCapacity) {
    auto newData = std::make_unique<std::unique_ptr<Figure<T>>[]>(newCapacity);
    for (size_t i = 0; i < count; ++i) {
        newData[i] = std::move(elems[i]);
    }
    elems = std::move(newData);
    capacity = newCapacity;
}

template<typename T>
double FigureArray<T>::TotalArea() const {
    double totalArea = 0;
    for (size_t i = 0; i < count; ++i) {
        if (elems[i]) {
            totalArea += (double)*(elems[i]);
        }
    }
    return totalArea;
}

#endif
