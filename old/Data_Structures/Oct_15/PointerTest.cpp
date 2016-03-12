#include <iostream>

using namespace std;

int main()
{
  int i = 10;
  int j = 20;

  int* i_ptr = &i;			// int* means "integer pointer"; * must be in that position
  int* j_ptr = &j;

  int* ii_ptr, jj_ptr;		// incorrect in C++ because the first one (ii_ptr) becomes a pointer and the second one (jj_ptr) becomes an integer
  // int *ii_ptr, *jj_ptr would define 2 pointers in 1 line;

  increment(i_ptr);
  cout << i_ptr << endl;		// outputs value of pointer: address of integer (address of location in memory in which integer is stored)
  cout << *i_ptr << endl;		// outputs value being stored AT pointer address

  return 0;
}

void increment(int* j)
{
  (*j) ++;			// address of i is stored as value of j; by using *j you're saying "I want the value of i". Allows access to outside variable
}
