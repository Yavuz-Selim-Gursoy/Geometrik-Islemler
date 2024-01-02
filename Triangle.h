#pragma once
#include "Dot.h"
class Triangle{

private:
    Dot dot1;
    Dot dot2;
    Dot dot3;

public:
    Triangle(Dot dotObj1, Dot dotObj2, Dot dotObj3);

    double calcArea();

    double calcCircumference();

    double * calcAngles();

    void setDot1(const Dot& dotObj);
    Dot getDot1();

    void setDot2(const Dot& dotObj);
    Dot getDot2();

    void setDot3(const Dot& dotObj);
    Dot getDot3();

    string toString();

    void print();
};