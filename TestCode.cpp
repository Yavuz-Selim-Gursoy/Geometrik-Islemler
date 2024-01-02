#include "LineSegment.h"
#include "Circle.h"
#include "Triangle.h"
#include <locale>



int main() {
    setlocale(LC_ALL, "Turkish");

    // Dot (Nokta) sýnýfý için test çýktýlarý
    cout << endl << "DOT SINIFI ÝÇÝN TEST ÇIKTILARI:" << endl;
    Dot dot1;
    Dot dot2(5);
    Dot dot3(3, 4);
    Dot dot4(dot3);
    Dot dot5(dot3, 1, -1);

    cout << "Oluþturulan 5 noktanýn x ve y deðerleri:" << endl;
    dot1.print();
    dot2.print();
    dot3.print();
    dot4.print();
    dot5.print();

    cout << "1. ve 2. noktalarýn güncel x ve y deðerleri:" << endl;
    dot1.setX(10);
    dot1.print();
    dot2.setCoordinates(25, 30);
    dot2.print();

    // LineSegment (DogruParcasi) sýnýfý için test sonuçlarý
    cout << endl << "LINESEGMENT SINIFI ÝÇÝN TEST SONUÇLARI:" << endl;
    Dot dot11;
    Dot dot21(3, 4);
    LineSegment lineSegment(dot11, dot21);
    LineSegment lineSegment2(lineSegment);
    LineSegment lineSegment3(dot21, 10, 45);

    cout << "Oluþturulan 3 doðru parçasýnýn baþlangýç ve bitiþ noktalarý:" << endl;
    lineSegment.print();
    lineSegment2.print();
    lineSegment3.print();

    cout << "2. doðru parçasýnýn baþlangýç ve bitiþ noktalarý:" << endl;
    lineSegment2.setDot1(Dot());
    lineSegment2.print();

    cout << "1. doðru parçasý için uzunluk deðeri: " << lineSegment.calcLength() << endl;
    cout << "1. doðru parçasý içib orta nokta: " << lineSegment.calcMidpoint().toString() << endl;

    // Circle (Daire) sýnýfý için test sonuçlarý
    cout << endl << "CIRCLE SINIFI ÝÇÝN TEST SONUÇLARI:" << endl;
    Dot center1(0, 0);
    Circle circle1(center1, 5);
    Circle circle2(circle1);
    Circle circle3(circle2, 3);

    cout << "Daire 1: ";
    circle1.print();
    cout << "Alan: " << circle1.calcArea() << ", Çevre: " << circle1.calcCircumference() << endl;

    cout << "Daire 2: ";
    circle2.print();
    cout << "Alan: " << circle2.calcArea() << ", Çevre: " << circle2.calcCircumference() << endl;

    cout << "Daire 3: ";
    circle3.print();
    cout << "Alan: " << circle3.calcArea() << ", Çevre: " << circle3.calcCircumference() << endl;

    cout << "Daire 1 ve Daire 2 Kesiþim Durumu: " << circle1.calcIntersection(circle2) << endl;
    cout << "Daire 1 ve Daire 3 Kesiþim Durumu: " << circle1.calcIntersection(circle3) << endl;

    // Triangle (Ucgen) sýnýfý için test sonuçlarý
    cout << endl << "TRIANGLE SINIFI ÝÇÝN TEST SONUÇLARI:" << endl;
    Triangle triangle(Dot(0, 0), Dot(4, 0), Dot(0, 3));

    cout << triangle.toString() << endl;
    cout << "Alan: " << triangle.calcArea() << endl;
    cout << "Çevre: " << triangle.calcCircumference() << endl;

    double *angles = triangle.calcAngles();
    cout << "Açýlar: " << angles[0] << ", " << angles[1] << ", " << angles[2] << endl;

    return 0;
}
