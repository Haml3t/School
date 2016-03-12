#include "LinearFunction.h"

LinearFunction::LinearFunction(int factor, int constant){
  this->constant = constant;
  this->factor = factor;
}

ostream& operator<ostream& out, LinearFunction L){
  out << L.factor << 'x' << '+' << L.constant;
			       }
LinearFunction(const LinearFunction& L){

}
