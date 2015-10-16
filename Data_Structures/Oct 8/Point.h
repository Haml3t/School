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
    // Don't need to override default copy constructor for this point class
    Point( const Point& , int i = 0);  // Two Implementation: 1. Point(Point&, int) 2. Point(Point&)

//    Point( Point );

    int getX() const {
        return x;
    }

    void setX(int x) {
        Point::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Point::y = y;
    }
    Point operator+( const Point& );
    Point operator+() { return *this; }

    friend void printFriend(const Point &);

    void printMember();

    friend std::ostream & operator<<(std::ostream& out, const Point& p);

    Point operator=(const Point& point) {
        x = point.x+1;
        y = point.y+1;
        return *this;
    }

private:
    int x;
    int y;
};

void printNonMember(const Point &);

#endif //DATA_STRUCTURES_FALL_2015_POINT_H
