#pragma once
#include "Dot.h"
class Circle{

private:
    Dot midpoint;
    double radius;

public:
    Circle(Dot& dotObj, double radiusIn);
    Circle(Circle& circleObj);
    Circle(Circle& circleObj, double x);

    double calcArea();

    double calcCircumference();

    int calcIntersection(Circle& circleObj);

    void setRadius(double radiusIn);
    double getRadius();

    void setMidpoint(const Dot& circleObj);
    Dot getMidpoint();

    string toString();

    void print();
};