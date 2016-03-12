//
// Created by Nooreddin Naghibolhosseini on 9/29/15.
//

#include "Circle.h"

int main()
{
    Circle circle01( 2 , 1 );
    Circle circle02( 1 , 3, 4);

//    Circle circle03 = circle03.add(circle01, circle02);
//    Circle circle03 = circle01.add(circle02);
//    Circle circle03 = circle01 + circle02;
//    Circle circle03 = circle01 + 3;
    Circle circle03;
    circle03 = circle03 + 3;
//    circle03 += 3;
    circle01 = circle03 += 3;
    ++circle03;
    circle03++;

//    int i = (1 == 2) ? 3 : 2;


    return 0;
}