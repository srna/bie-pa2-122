#include "complex.h"
#include <iostream>
#include <cmath>

Complex::Complex(int _re,int _im){
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

int Complex::getRe() const
{
	return re;
}

int Complex::getIm() const
{
	return im;
}

Complex add(const Complex& a, const Complex& b){
	return Complex(a.getRe()+b.getRe(),a.getIm()+b.getIm());
}

Complex diff(const Complex& a, const Complex& b){
	return Complex(a.getRe()-b.getRe(),a.getIm()-b.getIm());
}
