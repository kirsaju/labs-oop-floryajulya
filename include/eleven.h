#pragma once

#include <initializer_list>
#include <string>
class Eleven
{
public:
    Eleven();
    Eleven(const size_t &n, unsigned char t);
    Eleven(const std::initializer_list<unsigned char> &t);
    Eleven(const std::string &t);
    Eleven(const Eleven &other);
    Eleven(Eleven &&other) noexcept;
    ~Eleven() noexcept;

    Eleven &operator=(const Eleven &other);
    Eleven &operator+=(const Eleven &other);
    Eleven &operator-=(const Eleven &other);

    bool operator==(const Eleven &other) const;
    bool operator<(const Eleven &other) const;
    bool operator>(const Eleven &other) const;

    size_t getSize() const;
    unsigned char *getData() const;

private:
    size_t _size;
    unsigned char *_data;

    void validateBit(unsigned char digit);
};
