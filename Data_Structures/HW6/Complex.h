// Created by David Sugarman on 10/16/15

#include <iostream>
#include <ostream>

class Complex {
 public:
  Complex(double a = 1, double b = 1);
  void setA(double);
  void setB(double);
  double getA();
  double getB();

  complex_number operator+( complex_number );
  complex_number operator-( complex_number );

 private:
  double a;
  double b;
};
