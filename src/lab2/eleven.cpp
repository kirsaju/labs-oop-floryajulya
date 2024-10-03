#include "../include/eleven.h"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdexcept>

Eleven::Eleven() : _size{0}, _data{nullptr} {}

Eleven::Eleven(const size_t &n, unsigned char t)
{
    validateBit(t);
    _size = n;
    _data = new unsigned char[n];
    for (int i = 0; i < n; ++i)
    {
        _data[i] = t;
    }
}

Eleven::Eleven(const std::initializer_list<unsigned char> &t)
{
    _size = t.size();
    _data = new unsigned char[_size];

    size_t i = 0;
    for (unsigned char digit : t)
    {
        validateBit(digit);
        _data[i++] = digit;
    }
}

Eleven::Eleven(const std::string &t)
{
    _size = t.size();
    _data = new unsigned char[_size];

    for (size_t i = 0; i < _size; i++)
    {
        validateBit(t[i]);
        _data[i] = t[i];
    }
}

Eleven::Eleven(const Eleven &other)
{
    _size = other._size;
    _data = new unsigned char[_size];

    for (size_t i = 0; i < _size; ++i)
    {
        _data[i] = other._data[i];
    }
}

Eleven::Eleven(Eleven &&other) noexcept
{
    _size = other._size;
    _data = other._data;
    other._data = nullptr;
    other._size = 0;
}

Eleven &Eleven::operator=(const Eleven &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] _data;
    _size = other._size;
    _data = new unsigned char[_size];

    for (size_t i = 0; i < _size; ++i)
    {
        _data[i] = other._data[i];
    }

    return *this;
}

Eleven &Eleven::operator+=(const Eleven &other)
{
    int remember = 0;

    if (this->_size < other._size)
    {
        this->_data = static_cast<unsigned char *>(std::realloc(this->_data, other._size));
        std::memmove(this->_data + other._size - this->_size, this->_data, this->_size);
        std::memset(this->_data, '0', other._size - this->_size);
        this->_size = other._size;
    }
    for (int i = 0; i < this->_size; i++)
    {
        unsigned char dig1 = this->_data[this->_size - 1 - i];
        unsigned char dig2 = other._size - 1 < i ? '0' : other._data[other._size - 1 - i];

        int num1 = dig1 == 'A' ? 10 : dig1 - '0';
        int num2 = dig2 == 'A' ? 10 : dig2 - '0';
        int number = num1 + num2 + remember;
        remember = number > 10 ? 1 : 0;
        number = number % 11;
        unsigned char result = number == 10 ? 'A' : number + '0';
        this->_data[this->_size - 1 - i] = result;
    }

    if (remember == 1) {
        this->_data = static_cast<unsigned char *>(std::realloc(this->_data, ++this->_size));
        std::memmove(this->_data + 1, this->_data, this->_size);
        this->_data[0] = '1';
    }
    return *this;
}

Eleven &Eleven::operator-=(const Eleven &other)
{
    int remember = 0;

    if (this->_size < other._size) {
        throw std::invalid_argument("Subtraction result is negative.");
    }

    for (int i = 0; i < this->_size; i++) {
        unsigned char dig1 = this->_data[this->_size - 1 - i];
        unsigned char dig2 = other._size - 1 < i ? '0' : other._data[other._size - 1 - i];

        int num1 = dig1 == 'A' ? 10 : dig1 - '0';
        int num2 = dig2 == 'A' ? 10 : dig2 - '0';

        int number = num1 - num2 - remember;

        if (number < 0) {
            number += 11;
            remember = 1;
        } else {
            remember = 0;
        }

        unsigned char result = number == 10 ? 'A' : number + '0';
        this->_data[this->_size - 1 - i] = result;
    }

    if (this->_data[0] == '0' && this->_size > 1) {
        std::memmove(this->_data, this->_data + 1, --this->_size);
        this->_data = static_cast<unsigned char *>(std::realloc(this->_data, this->_size));
    }

    if (remember == 1) {
        throw std::invalid_argument("Subtraction result is negative");
    }

    return *this;
}

bool Eleven::operator==(const Eleven &other) const
{
    if (_size != other._size)
    {
        return false;
    }

    for (size_t i = 0; i < _size; i++)
    {
        if (_data[i] != other._data[i])
        {
            return false;
        }
    }
    return true;
}

bool Eleven::operator<(const Eleven &other) const
{
    if (_size > other._size)
    {
        return false;
    }

    if (_size < other._size)
    {
        return true;
    }

    for (size_t i = 0; i < _size; i++)
    {
        if (_data[i] < other._data[i])
        {
            return true;
        }
        if (_data[i] > other._data[i])
        {
            return false;
        }
    }
    return false;
}

bool Eleven::operator>(const Eleven &other) const
{
    return other < *this;
}

size_t Eleven::getSize() const
{
    return _size;
}

unsigned char *Eleven::getData() const
{
    return _data;
}

Eleven::~Eleven() noexcept
{
    delete[] _data;
    _data = nullptr;
    _size = 0;
}

void Eleven::validateBit(unsigned char digit)
{
    if (digit < '0' || digit > '9')
    {
        if (digit != 'A')
        {
            throw std::invalid_argument("Invalid eleven digit");
        }
    }
}

 