//
// Created by Nooreddin Naghibolhosseini on 10/8/15.
//

//#ifndef DATA_STRUCTURES_FALL_2015_CIRCLE_H
//#define DATA_STRUCTURES_FALL_2015_CIRCLE_H

#include "Point.h"

class Circle {
public:

    Circle( Point center )
    {
        Circle::center = center;
    }

    // int i = 0;
    // int j = 1;
    // i = j   puts the value of j inside i returns the value of i
    Circle operator=( const Circle& ); // Its not necessary to override this for Circle class

private:
    Point center = Point(0, 0);
};


//#endif //DATA_STRUCTURES_FALL_2015_CIRCLE_H
