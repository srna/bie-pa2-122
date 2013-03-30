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

Complex operator*(const Complex& a, const Complex& b)
{
    // (a,b) * (c,d) = (ac - bd, ad + bc)
    float real = a.re * b.re - a.im * b.im;
    float imag = a.re * b.im + a.im * b.re;

    return Complex(real, imag);
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    c.print(os);
    return os;
}

// Parser 5 + -3i
std::istream& operator>> (std::istream& is, Complex& cpx)
{
    int state = 1; // 1 = reading re, 2 = reading im
    char c;
    while(is.good() && !is.eof())
    {
        c = is.peek();
        if(c == EOF)
            break;
        switch(c)
        {
            case '\n':
            case '\r':
            case '\t':
            case ' ':
                is.get(c);
                break;
            case '+':
                is.get(c);
                state = 2;
                break;
            case 'i':
                is.get(c);
                return is;
            default:
                if(state == 1)
                    is >> cpx.re;
                else if(state == 2)
                    is >> cpx.im;
                break;
        }
    }
    return is;
}

