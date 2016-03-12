//
// Created by Nooreddin Naghibolhosseini on 10/6/15.
//
#include "Point.h"

//void toZero(int&);
void print(const int& );

int main()
{
    Point p1(1,2);
//    Point p2(2,3);
    int x = 1;
    const int& y = x;
//    toZero(x);
//    print(x);
//    std::cout << x;

    std::cout << p1;
//    p1 << std::cout;
//    Point p3 = p1 + p2;

//    Point* p4 = nullptr;
//    std::cout << &p3;

//    std::cout << p4;
    return 0;
}

//
//void toZero(int& i)
//{
//    i = 0;
//}

void print(const int& x)
{
    std::cout << x;
}
