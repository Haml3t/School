//
// Created by Nooreddin Naghibolhosseini on 9/29/15.
//

namespace NOOREDDIN_AT_GMAIL {

#include "Circle.h"
#include <cmath>

Circle::Circle(int x, int y, int radius) {
    setX(x);
    setY(y);
    setRadius(radius);
}

void Circle::setX(int x) {
    this->x = x;
}

void Circle::setY(int y) {
    this->y = y;
}

void Circle::setRadius(int r) {
    this->r = r;
}

int Circle::getY() const {
    return y;
}

int Circle::getRadius() const {
    return r;
}

double Circle::getArea() {
    return M_PI * r * r;
}

//
//Circle Circle::add( Circle circle1, Circle circle2 ) {
//    return Circle(circle1.x + circle2.x,
//                  circle1.y + circle2.y,
//                  circle1.r + circle2.r);
//}
//
//Circle Circle::add( Circle circle ) {
//    return Circle(x + circle.x,
//                  y + circle.y,
//                  r + circle.r);
//}
//
//Circle Circle::operator+( Circle circle ) {
//    return Circle(x + circle.x,
//                  y + circle.y,
//                  r + circle.r);
//}

Circle Circle::operator+(int r) {
    return Circle(x, y, this->r + r);
}

Circle Circle::operator+=(int r) {
    this->r += r;
    Circle(x, y, this->r);
    return *this;
}

Circle Circle::operator++() {
    this->r++;
    return *this;
}

Circle Circle::operator++(int x) {
    this->r++;
    return *this;
}

}
