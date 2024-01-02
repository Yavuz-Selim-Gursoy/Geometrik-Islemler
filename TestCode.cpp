#include "LineSegment.h"
#include "Circle.h"
#include "Triangle.h"
#include <locale>



int main() {
    setlocale(LC_ALL, "Turkish");

    // Dot (Nokta) s�n�f� i�in test ��kt�lar�
    cout << endl << "DOT SINIFI ���N TEST �IKTILARI:" << endl;
    Dot dot1;
    Dot dot2(5);
    Dot dot3(3, 4);
    Dot dot4(dot3);
    Dot dot5(dot3, 1, -1);

    cout << "Olu�turulan 5 noktan�n x ve y de�erleri:" << endl;
    dot1.print();
    dot2.print();
    dot3.print();
    dot4.print();
    dot5.print();

    cout << "1. ve 2. noktalar�n g�ncel x ve y de�erleri:" << endl;
    dot1.setX(10);
    dot1.print();
    dot2.setCoordinates(25, 30);
    dot2.print();

    // LineSegment (DogruParcasi) s�n�f� i�in test sonu�lar�
    cout << endl << "LINESEGMENT SINIFI ���N TEST SONU�LARI:" << endl;
    Dot dot11;
    Dot dot21(3, 4);
    LineSegment lineSegment(dot11, dot21);
    LineSegment lineSegment2(lineSegment);
    LineSegment lineSegment3(dot21, 10, 45);

    cout << "Olu�turulan 3 do�ru par�as�n�n ba�lang�� ve biti� noktalar�:" << endl;
    lineSegment.print();
    lineSegment2.print();
    lineSegment3.print();

    cout << "2. do�ru par�as�n�n ba�lang�� ve biti� noktalar�:" << endl;
    lineSegment2.setDot1(Dot());
    lineSegment2.print();

    cout << "1. do�ru par�as� i�in uzunluk de�eri: " << lineSegment.calcLength() << endl;
    cout << "1. do�ru par�as� i�ib orta nokta: " << lineSegment.calcMidpoint().toString() << endl;

    // Circle (Daire) s�n�f� i�in test sonu�lar�
    cout << endl << "CIRCLE SINIFI ���N TEST SONU�LARI:" << endl;
    Dot center1(0, 0);
    Circle circle1(center1, 5);
    Circle circle2(circle1);
    Circle circle3(circle2, 3);

    cout << "Daire 1: ";
    circle1.print();
    cout << "Alan: " << circle1.calcArea() << ", �evre: " << circle1.calcCircumference() << endl;

    cout << "Daire 2: ";
    circle2.print();
    cout << "Alan: " << circle2.calcArea() << ", �evre: " << circle2.calcCircumference() << endl;

    cout << "Daire 3: ";
    circle3.print();
    cout << "Alan: " << circle3.calcArea() << ", �evre: " << circle3.calcCircumference() << endl;

    cout << "Daire 1 ve Daire 2 Kesi�im Durumu: " << circle1.calcIntersection(circle2) << endl;
    cout << "Daire 1 ve Daire 3 Kesi�im Durumu: " << circle1.calcIntersection(circle3) << endl;

    // Triangle (Ucgen) s�n�f� i�in test sonu�lar�
    cout << endl << "TRIANGLE SINIFI ���N TEST SONU�LARI:" << endl;
    Triangle triangle(Dot(0, 0), Dot(4, 0), Dot(0, 3));

    cout << triangle.toString() << endl;
    cout << "Alan: " << triangle.calcArea() << endl;
    cout << "�evre: " << triangle.calcCircumference() << endl;

    double *angles = triangle.calcAngles();
    cout << "A��lar: " << angles[0] << ", " << angles[1] << ", " << angles[2] << endl;

    return 0;
}
