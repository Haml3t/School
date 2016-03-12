//
// Created by Nooreddin Naghibolhosseini on 10/6/15.
//

#include "Point.h"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point Point::operator+(const Point &point) {

    return Point(x + point.x, y + point.y);
}

void printFriend(const Point& p )
{
    std::cout << p.x << " " << p.y << std::endl;
}

void printNonMember(const Point& p)
{
//    std::cout << p.getX() << " " << p.getY() << std::endl;
}

void Point::printMember()
{
    std::cout << x << " " << y << std::endl;
}

void operator<<(std::ostream& out, const Point& p)
{
    out << "( " << p.x << " , " << p.y << " )";
}
