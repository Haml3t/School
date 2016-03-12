// Created by David Sugarman on 10/5/15

#include "Complex.h"
using namespace std;

int main()
{
  Complex c1( 3 , -4);
  Complex c2( -2 , 8);

  Complex c3;
  Complex c4;
  Complex c5;
  Complex c6 = c2;

  c3 = c1 + c2;
  c4 = c1 - c2;
  c5 = c4;

  cout << "c3 = " << c3.getA() << " + " << c3.getB() << "i" << endl;
  cout << "c4 = " << c4.getA() << " + " << c4.getB() << "i" << endl;
  cout << "c5 = " << c5.getA() << " + " << c5.getB() << "i" << endl;
  cout << "c6 = " << c6.getA() << " + " << c6.getB() << "i" << endl;

  return 0;
}
