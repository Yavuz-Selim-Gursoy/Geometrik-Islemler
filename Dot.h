#pragma once
#include <iostream>
#include <cmath>
#include <array>
#include <locale>
using namespace std;

class Dot{

private:
    double x;
    double y;

public:
    Dot();
    Dot(double num);
    Dot(double xIn, double yIn);
    Dot (const Dot& dotObj);
    Dot(const Dot& dotObj, double ofsetX, double ofsetY);

    double getX();
    void setX(double newX);

    double getY();
    void setY(double newY);

    void setCoordinates(double xIn, double yIn);

    string toString();

    void print();
};

