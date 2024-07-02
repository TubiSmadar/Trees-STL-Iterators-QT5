// Tuvia Smadar
// gunslokij@gmail.com

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>

// Class to represent a complex number
class Complex {
private:
    double real; // Real part of the complex number
    double imag; // Imaginary part of the complex number

public:
    // Constructor with default values for real and imaginary parts
    Complex(double r = 0, double i = 0);

    // Getter for the real part
    double get_real() const;

    // Getter for the imaginary part
    double get_imag() const;

    // Converts the complex number to a string representation
    std::string to_string() const;

    // Friend function to allow ostream to access private members of Complex
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    
    // Equality operator to compare two Complex numbers
    bool operator==(const Complex& other) const;

    // Inequality operator to compare two Complex numbers
    bool operator!=(const Complex& other) const;

    // Greater than operator to compare two Complex numbers
    bool operator>(const Complex& other) const;

    // Less than operator to compare two Complex numbers
    bool operator<(const Complex& other) const;
};

#endif // COMPLEX_HPP
