#include "complex.h"
#include <iostream>
#include <cmath>

Complex::Complex(float _re,float _im){
	re=_re;
	im=_im;
}
void Complex::print() const {
	std::cout<<re<<"+"<<im<<"i";
}

float Complex::abs() const
{
	return sqrt(re*re+im*im);
}

float Complex::getRe() const
{
	return re;
}

float Complex::getIm() const
{
	return im;
}

Complex operator+(const Complex& a, const Complex& b){
	return Complex(a.re+b.re,a.im+b.im);
}

Complex operator-(const Complex& a, const Complex& b){
	return Complex(a.re-b.re,a.im-b.im);
}

std::ostream& operator<< (std::ostream& os, const Complex& c)
{
	os << c.re << "+" << c.im << "i";
	return os;
}
