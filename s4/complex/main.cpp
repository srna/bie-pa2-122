/* main.cpp */
#include <iostream>
using namespace std;
#include "complex.h"

int main(void) {
  Complex x(1,1), y(2,2), z;
  float a = 1.2;
  z = a;
  cout << z << endl;
  cout << "x=" << x << endl;
  cout << "y=" << y << endl;
  z = x + y;
  cout << "x+y=" << z << endl;
  z = x - y;
  cout << "x-y=" << z << endl;
  cout << "x+1=" << x+1 << endl;
  cout << "2+x=" << 2+x << endl;

  cout << Complex(0, 0) << endl;
  cout << Complex(0, -1) << endl;
  cout << Complex(0, 1) << endl;
  cout << Complex(0, 2) << endl;

  cout << (Complex(3,4) * Complex(6,-5)) << endl;
  cout << (Complex(2,6) * Complex(0,1)) << endl;
  cout << (8 * Complex(-2,-1)) << endl;
  cout << (0 * Complex(-2,-1)) << endl;

  return 0;
}

