#ifndef __COMPLEX_H_
#define __COMPLEX_H_
#include <iostream>

class Complex {
    float re, im;

public:
    Complex(float _re = 0, float _im = 0);

    void print(std::ostream &os = std::cout) const;
    float abs() const;
    float getRe() const;
    float getIm() const;

    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator-(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);
    friend std::ostream& operator<< (std::ostream& os, const Complex& c);
    friend std::istream& operator>> (std::istream& is, Complex& c);
};

#endif // __COMPLEX_H_

