#include "complex.hpp"
#include <cmath>

Complex Complex::operator+(const Complex& other) const {
    return Complex(r + other.r, i + other.i);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(r - other.r, i - other.i);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(r * other.r - i * other.i, r * other.i + i * other.r);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.r * other.r + other.i * other.i;
    return Complex((r * other.r + i * other.i) / denominator, (i * other.r - r * other.i) / denominator);
}

bool Complex::operator<(const Complex& other) const {
    return std::sqrt(r * r + i * i) < std::sqrt(other.r * r + other.i * i);
}

bool Complex::operator>(const Complex& other) const {
    return other < *this;
}

bool Complex::operator<=(const Complex& other) const {
    return !(other < *this);
}

bool Complex::operator>=(const Complex& other) const {
    return !(*this < other);
}

bool Complex::operator==(const Complex& other) const {
    return r == other.r && i == other.i;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.r << " + " << c.i << "i";
    return os;
}