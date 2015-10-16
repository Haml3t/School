//
// Created by Nooreddin Naghibolhosseini on 10/6/15.
//

#ifndef DATA_STRUCTURES_FALL_2015_POINT_H
#define DATA_STRUCTURES_FALL_2015_POINT_H


#include <iostream>

class Point
{
public:
    Point( int x, int y );

    Point operator+( const Point& );
    Point operator+() { return *this; }

    friend void printFriend(const Point &);

    void printMember();

    friend void operator<<(std::ostream& out, const Point& p);

private:
    int x;
    int y;
};

void printNonMember(const Point &);

#endif //DATA_STRUCTURES_FALL_2015_POINT_H
