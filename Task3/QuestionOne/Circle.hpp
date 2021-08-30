#ifndef TASK3_CIRCLE_H
#define TASK3_CIRCLE_H


#pragma once

const double pi = 3.141592;

class Circle {
public:
    Circle(double radius_);
    int get_area() const;
    double get_circumference() const;
private:
    double radius;
};

#endif //TASK3_CIRCLE_H