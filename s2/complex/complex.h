#ifndef __COMPLEX_H_
#define __COMPLEX_H_

class Complex {
	int re, im;
public:
	Complex(int _re = 0, int _im = 0);
	void print() const;
	float abs() const;
	int getRe() const;
	int getIm() const;
};

Complex add(const Complex& a, const Complex& b);

Complex diff(const Complex& a, const Complex& b);

#endif