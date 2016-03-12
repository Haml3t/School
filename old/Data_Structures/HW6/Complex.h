// Created by David Sugarman on 10/16/15

//PRECONDITION: a complex number class is specified, made up of a real component a and an imaginary component b
//POSTCONDITION: the complex class can be copied, assigned, added and subtracted
#include <iostream>
#include <ostream>

class Complex {
 public:
  Complex(double a = 1, double b = 1);
  Complex(const Complex &other);

  void setA(double);
  void setB(double);
  double getA();
  double getB();

  Complex& operator=( const Complex &other );
  Complex operator+( Complex );
  Complex operator-( Complex );

 private:
  double a;
  double b;
};
