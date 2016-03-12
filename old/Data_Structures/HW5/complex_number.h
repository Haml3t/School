// Created by David Sugarman on 10/5/15

#include <iostream>
#include <ostream>

class complex_number {
 public:
  complex_number(double a = 1, double b = 1);
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
