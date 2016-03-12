// Created by David Sugarman on 10/5/15

#include "complex_number.h"

  complex_number::complex_number(double a, double b) {
    setA(a);
    setB(b);
  }

  void complex_number::setA(double a) {
    this->a = a;
  }

  void complex_number::setB(double b) {
    this->b = b;
  }

  double complex_number::getA() {
    return a;
  }

  double complex_number::getB() {
    return b;
  }

  complex_number complex_number::operator+(complex_number c) {
    return complex_number(a + c.a,
			  b + c.b);
  }
  complex_number complex_number::operator-(complex_number c) {
    return complex_number(a - c.a,
			  b - c.b);
  }
