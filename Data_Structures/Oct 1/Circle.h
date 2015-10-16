//
// Created by Nooreddin Naghibolhosseini on 9/29/15.
//

namespace NOOREDDIN_AT_GMAIL
{
#ifndef DATA_STRUCTURES_FALL_2015_CIRCLE_H
#define DATA_STRUCTURES_FALL_2015_CIRCLE_H

#include <iostream>
#include <ostream>

    class Circle {
    public:
        Circle(int x = 1, int y = 1, int radius = 1);
        void setX(int);
        void setY(int);
        void setRadius(int);
        int getX() const { return x; }
        int getY() const;
        int getRadius() const;
        double getArea();

    //    Circle add( Circle, Circle );
    //    Circle add( Circle );
    //    Circle operator+( Circle );
        Circle operator+( int );
        Circle operator+=( int );
        Circle operator++();
        Circle operator++( int );
        friend std::ostream& operator<<( std::ostream& out, Circle );
    private:
        int x;
        int y;
        int r;
    };


#endif //DATA_STRUCTURES_FALL_2015_CIRCLE_H
}