// Created by David Sugarman on 10/16/15

#include "Complex.h"

  Complex::Complex(double a, double b) {
    setA(a);
    setB(b);
  }

  void Complex::setA(double a) {
    this->a = a;
  }

  void Complex::setB(double b) {
    this->b = b;
  }

  double Complex::getA() {
    return a;
  }

  double Complex::getB() {
    return b;
  }

  Complex Complex::operator+(Complex c) {
    return Complex(a + c.a,
			  b + c.b);
  }
  Complex Complex::operator-(Complex c) {
    return Complex(a - c.a,
			  b - c.b);
  }
