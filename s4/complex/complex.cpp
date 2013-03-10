#include "complex.h"
#include <iostream>
#include <cmath>

Complex::Complex(float _re, float _im)
    : re(_re)
    , im(_im)
{
}

void Complex::print(std::ostream &os) const
{
    const char sign = im < 0 ? '-' : '+';

    if (re != 0 || im == 0)
        os << re;

    if (im != 0) {
        if (re != 0 || im < 0)
            os << sign;

        if (std::abs(im) != 1)
            os << std::abs(im);

        os << "i";
    }
}

float Complex::abs() const
{
    return sqrt(re * re + im * im);
}

float Complex::getRe() const
{
    return re;
}

float Complex::getIm() const
{
    return im;
}

Complex operator+(const Complex& a, const Complex& b)
{
    return Complex(a.re + b.re, a.im + b.im);
}

Complex operator-(const Complex& a, const Complex& b)
{
    return Complex(a.re - b.re, a.im - b.im);
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    c.print(os);
    return os;
}

