// Tuvia Smadar
// gunslokij@gmail.com
#include "Complex.hpp"
#include <sstream>

// Constructor to initialize a Complex number with real and imaginary parts
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Getter for the real part of the Complex number
double Complex::get_real() const {
    return real;
}

// Getter for the imaginary part of the Complex number
double Complex::get_imag() const {
    return imag;
}

// Converts the Complex number to a string representation
std::string Complex::to_string() const {
    std::ostringstream oss;
    oss << real << " + " << imag << "i";
    return oss.str();
}

// Overloaded stream insertion operator to output the Complex number
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.get_real() << " + " << c.get_imag() << "i";
    return os;
}

// Equality operator to compare two Complex numbers
bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

// Inequality operator to compare two Complex numbers
bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// Greater than operator to compare two Complex numbers
bool Complex::operator>(const Complex& other) const {
    return (real > other.real) || (real == other.real && imag > other.imag);
}

// Less than operator to compare two Complex numbers
bool Complex::operator<(const Complex& other) const {
    return (real < other.real) || (real == other.real && imag < other.imag);
}
