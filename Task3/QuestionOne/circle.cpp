#include "circle.hpp"

circle::circle(double radius_) : radius(radius_) {}

int circle::get_area() const{
    return pi * radius * radius;
}

double circle::get_circumference() const {
    double circumference = 2.0 * pi * radius;
    return circumference;
}

