//
// Created by Nooreddin Naghibolhosseini on 10/8/15.
//

#include "Circle.h"

Circle Circle::operator=(const Circle &circle)
{
    center = circle.center;
    return *this;
}
