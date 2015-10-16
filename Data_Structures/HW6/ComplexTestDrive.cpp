// Created by David Sugarman on 10/5/15

#include "Complex.h"
using namespace std;

int main()
{
  Complex c1( 3 , -4);
  Complex c2( -2 , 8);

  Complex c3;
  Complex c4;

  c3 = c1 + c2;
  c4 = c1 - c2;

  cout << "c3 = " << c3.getA() << "i + " << c3.getB() << "j" << endl;
  cout << "c4 = " << c4.getA() << "i + " << c4.getB() << "j" << endl;

  return 0;
}
