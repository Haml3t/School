//
// Created by Nooreddin Naghibolhosseini on 10/6/15.
//
#include "Point.h"
#include "Circle.h"

//void toZero(int&);
void print(const int& );

int main()
{
    Point p1(1,2);
    Point p2(p1);  // Point p2 = p1;
//    int i = p1.x;   NOT VALID
    int x = 1;
    const int& y = x;
//    toZero(x);
//    print(x);
//    std::cout << x;

    // operator<<(cout, p1)
    // output = cout


    std::cout << p1;
    std::cout << p2;
    std::cout << "Point " << 'p' << 1 << ": " << p1 << std::endl;
    std::cout << p1 << p2;
//    p1 << std::cout;
//    Point p3 = p1 + p2;

//    Point* p4 = nullptr;
//    std::cout << &p3;

//    std::cout << p4;

    Circle circle1(p1);
    Circle circle2(circle1);

    circle2 = circle1;

    p1 = p2;

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
