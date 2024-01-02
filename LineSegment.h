#pragma once
#include "Dot.h"
class LineSegment{

private:
    Dot dot1;
    Dot dot2;
    double length;
    double slope;

public:
    LineSegment(const Dot& dotObj1, const Dot& dotObj2);
    LineSegment(LineSegment& lineObj);
    LineSegment(Dot& dotObj, double lengthIn, double slopeIn);

    double calcLength();

    Dot calcIntersectPoint(Dot& dotObj);

    Dot calcMidpoint();

    void setDot1(const Dot& dotObj);
    Dot getDot1();

    void setDot2(const Dot& dotObj);
    Dot getDot2();

    void setLength(double lengthIn);
    double getLength();

    void setSlope(double slopeIn);
    double getSlope();

    string toString();

    void print();
};