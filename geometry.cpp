//
// Created by Yavuz Selim Gürsoy on 19.12.2023.
//

#include "Dot.h"
#include "LineSegment.h"
#include "Circle.h"
#include "Triangle.h"
#include <iostream>


using namespace std;

Dot::Dot() {
    setCoordinates(0, 0);
}
Dot::Dot(double num) {
    setCoordinates(num, num);
}
Dot::Dot(const Dot &dotObj) {
    setCoordinates(dotObj.x, dotObj.y);
}
Dot::Dot(const Dot &dotObj, double ofsetX, double ofsetY) {
    double newX = ofsetX + dotObj.x;
    double newY = ofsetY + dotObj.y;

    setCoordinates(newX, newY);
}
Dot::Dot(double xIn, double yIn) {
    setCoordinates(xIn, yIn);
}
// Ödevdeki yönergelere göre oluşturulmuş 5 nokta constructor'ı.
// Birincisi nokta nesnesinin x ve y koordinatlarını 0 olarak ayarlar.
// İkincisi nokta nesnesinin x ve y koordinatlarını girilen değer olarak ayarlar.
// Üçüncüsü nokta nesnesinin x ve y koordinatlarını girilen x ve y değerleri olarak ayarlar.
// Dördüncüsü nokta nesnesinin x ve y koordinatlarını başka bir nokta nesnesinin x ve y koordinatları olarak ayarlar.
// Beşincisi nokta nesnesinin başka bir nokta nesnesinin x ve y koordinatlarını girilen sayıyla çarpar ve x ve y olarak ayarlar.


double Dot::getX() {
    return this -> x;
}

void Dot::setX(double newX) {
    this -> x = newX;
}


double Dot::getY() {
    return this -> y;
}

void Dot::setY(double newY) {
    this -> y = newY;
}

// Nokta sınıfına özel setter getter fonksiyonlar. Bu fonksiyonlar kullanıcının özelliklere direkt olarak erişmesini engeller.

void Dot::setCoordinates(double xIn, double yIn) {
    setX(xIn);
    setY(yIn);
}
// setCoordinates() fonksiyonu tek seferde iki koordinata atama yapar.

string Dot::toString() {
    string returnX = to_string(getX());
    string returnY = to_string(getY());

    string returnString = "\nX: " + returnX + "\n" + "Y: " + returnY + "\n";

    return returnString;
    //toString() fonksiyonu noktaları bir string değer halinde döndürür.
}

void Dot::print() {
    cout << "Nokta nesnesinin koordinatlari:\n" << toString() << endl;
    // print() fonksiyonu toString fonksiyonundan dönen string değerini ekrana yazdırır.
}




LineSegment::LineSegment(const Dot& dotObj1, const Dot& dotObj2){
    setDot1(dotObj1);
    setDot2(dotObj2);
}
LineSegment::LineSegment(LineSegment &lineObj) {
    setDot1(lineObj.getDot1());
    setDot2(lineObj.getDot2());
}
LineSegment::LineSegment(Dot &dotObj, double lengthIn, double slopeIn) {
    double dotObj2x = dotObj.getX() + lengthIn / sqrt(1 + pow(slopeIn, 2));
    double dotObj2y = dotObj.getY() + slopeIn * (dotObj.getX() - dotObj2x);

    dot2.setX(dotObj2x);
    dot2.setY(dotObj2y);
}
// Doğru parçası sınıfının 3 constructor'ı.
// Birincisi iki nokta nesnesi alır ve bu noktalardan bir doğru parçası nesnesi oluşturur.
// İkincisi bir doğru parçası nesnesi alır ve o doğru parçası nesnesinin özelliklerinden yeni bir doğru parçası nesnesi oluşturur.
// Üçüncüsü bir orta nokta, eğim ve uzunluk değerlerini alır ve bunlara uygun hesaplamaları yapıp bir doğru parçası nesnesi oluşturur.


double LineSegment::calcLength() {
    double lengthCalc = sqrt(pow((getDot1().getX() - getDot2().getX()),2) + pow((getDot1().getY() - getDot2().getY()),2));
    return lengthCalc;
    //calcLength() fonksiyonu doğru parçasının uzunluğunu hesaplar (iki noktası bilinen doğru parçasının uzunluğu formülünü kullanarak).
}


Dot LineSegment::calcIntersectPoint(Dot &dotObj) {
    setSlope((dot2.getY() - dot1.getY()) / (dot2.getX() - dot1.getX()));

    double slope2 = -1 / getSlope();

    double xIntersect = (getSlope() * dot1.getX() - slope2 * dotObj.getX() + dotObj.getY() - dot1.getY()) / (getSlope() - slope2);
    double yIntersect = getSlope() * (xIntersect - dot1.getX()) + dot1.getY();

    return Dot(xIntersect, yIntersect);
    //calcIntersectPoint() fonksiyonu; kendisine parametre olarak verilen nokta nesnesinden, doğru parçasına doğru çizilecek olan dik başka bir doğru parçasının; doğru parçasını hangi noktadan keseceğini döndürür.
}


Dot LineSegment::calcMidpoint() {
    double midX = dot1.getX() + dot2.getX();
    double midY = dot1.getY() + dot2.getY();

    return Dot(midX/2.0, midY/2.0);
    //calcMidpoint fonksiyonu doğru parçası nesnesinin orta noktasını hesaplar ve bir nokta nesnesi olarak döndürür.
}


void LineSegment::setDot1(const Dot& dotObj) {
    this -> dot1 = dotObj;
}
Dot LineSegment::getDot1() {
    return this -> dot1;
}


void LineSegment::setDot2(const Dot& dotObj) {
    this -> dot2 = dotObj;
}
Dot LineSegment::getDot2() {
    return this -> dot2;
}



void LineSegment::setLength(double lengthIn) {
    this -> length = lengthIn;
}
double LineSegment::getLength() {
    return this -> length;
}


void LineSegment::setSlope(double slopeIn) {
    this -> slope = slopeIn;
}
double LineSegment::getSlope() {
    return this -> slope;
}

// Doğru parçasına ait nokta nesnelerini ayarlamak için setter getter fonksiyonları.

string LineSegment::toString() {
    string dot1Str = dot1.toString();
    string dot2Str = dot2.toString();

    string outputStr = "Baslangic noktasi:\n" + dot1Str + "\nBitis noktasi:\n"+ dot2Str;
    return outputStr;
    // toString() fonksiyonu doğru parçası nesnesinin özelliklerini bir string değere atar
}


void LineSegment::print() {
    cout << "Dogru parcasi ozellikleri:\n" << toString();
    // print() fonksiyonu toString() fonksiyonundan dönen değeri ekrana yazdırır.
}




Circle::Circle(Dot& dotObj, double radiusIn) {
    setRadius(radiusIn);
    setMidpoint(dotObj);
}
Circle::Circle(Circle &circleObj) {
    setRadius(circleObj.getRadius());
    setMidpoint(circleObj.getMidpoint());
}
Circle::Circle(Circle &circleObj, double x) {
    setMidpoint(circleObj.getMidpoint());
    setRadius(circleObj.getRadius() * x);
}

// Daire sınıfının 3 constructor'ı.
// Birincisi merkez noktayı -bir nokta nesnesi olarak- ve yarıçap değerini alarak bir daire nesnesi oluşturur.
// İkincisi bir daire nesnesi alarak onun bir kopyasını oluşturur.
// Üçüncüsü bir daire nesnesi ve bir yarıçap değeri alarak dairenin yarıçapıyla parametre olarak alınan yarıçap değerini çarpar ve elde ettiği yarıçap değeriyle yeni bir daire nesnesi oluşturur.
//


double Circle::calcArea() {
    double area = M_PI * pow(getRadius(),2);
    return area;
    //calcArea() fonksiyonu daire nesnesinin alanını hesaplar ve döndürür.
}



double Circle::calcCircumference() {
    double circumference = 2 * M_PI * getRadius();
    return circumference;
    //calcCircumference() fonksiyonu dairenin çevresini hesaplar ve döndürür.

}


int Circle::calcIntersection(Circle &circleObj) {
    double radiusCombined = circleObj.getRadius() + getRadius();
    double distanceBetweenMidpoints = sqrt(pow(getMidpoint().getX() - circleObj.getMidpoint().getX(), 2) +
                                           pow(getMidpoint().getY() - circleObj.getMidpoint().getY(), 2));

    if (distanceBetweenMidpoints == 0 && circleObj.getRadius() == getRadius()){
        return 1;
    }

    else if (distanceBetweenMidpoints < radiusCombined){
        return 0;
    }

    else{
        return 2;
    }
    // calcIntersection() fonksiyonu iki daire nesnesinin kesişip kesişmediğini, çakışık olup olmadığını veya hiç ilişkisinin olup olmadığını gösterir.
}


void Circle::setRadius(double radiusIn) {
    this -> radius = radiusIn;
}
double Circle::getRadius() {
    return this -> radius;
}


void Circle::setMidpoint(const Dot& circleObj) {
    this -> midpoint = circleObj;
}
Dot Circle::getMidpoint() {
    return this -> midpoint;
}
// Daire sınıfa özel setter getter fonksiyonlar.

string Circle::toString() {
    string strCircle = "Dairenin merkezi:\n" + getMidpoint().toString() + "\nDairenin yaricapi:\n" + to_string(getRadius()) + "\n";
    return strCircle;
    //toString() fonksiyonu dairenin merkezi ve yarıçapını string bir değere atar ve bu değeri geri döndürür.
}

void Circle::print() {
    cout << "Daire ozellikleri:\n" << toString();
    //print() fonksiyonu toString fonksiyonunu kullanarak dairenin özelliklerini yazdırır.
}




Triangle::Triangle(Dot dotObj1, Dot dotObj2, Dot dotObj3) {
    setDot1(dotObj1);
    setDot2(dotObj2);
    setDot3(dotObj3);
}
// Üçgen sınıfının başlatılması için parametre olarak üç nokta nesnesi alan constructor.


double Triangle::calcArea() {
    LineSegment line1(getDot1(), getDot2());
    LineSegment line2(getDot1(), getDot3());
    LineSegment line3(getDot2(), getDot3());

    double a = line1.calcLength();
    double b = line2.calcLength();
    double c = line3.calcLength();

    double s = (a + b + c) / 2.0;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    return area;
    // calcArea() fonksiyonu 1, 2 ve 3. noktaları kullanarak önce 3 tane doğru oluşturur.
    // Bu doğruların uzunluklarını hesaplamak için üç kenarının uzunluğu bilinen üçgenin alanını hesaplayan formülü kullanır.
    // İşlem sonunda hesapladığı alanı döndürür.
}


double Triangle::calcCircumference() {
    LineSegment line1(getDot1(), getDot2());
    LineSegment line2(getDot1(), getDot3());
    LineSegment line3(getDot2(), getDot3());

    return line1.calcLength() + line2.calcLength() + line3.calcLength();
    // calcCircumference() fonksiyonu calcArea() fonksiyonu gibi önce 3 doğru oluşturur ve bu doğruları toplayarak üçgenin çevresine ulaşır.
}


double * Triangle::calcAngles() {
    double *resultArray;

    LineSegment line1(getDot1(), getDot2());
    LineSegment line2(getDot1(), getDot3());
    LineSegment line3(getDot2(), getDot3());

    double a = line1.calcLength();
    double b = line2.calcLength();
    double c = line3.calcLength();

    double aRadian = std::acos((b * b + c * c - a * a) / (2 * b * c));
    double bRadian = std::acos((a * a + c * c - b * b) / (2 * a * c));
    double cRadian = std::acos((a * a + b * b - c * c) / (2 * a * b));

    double aDegrees = aRadian * (180.0 / M_PI);
    double bDegrees = bRadian * (180.0 / M_PI);
    double cDegrees = cRadian * (180.0 / M_PI);

    resultArray[0] = aDegrees;
    resultArray[1] = bDegrees;
    resultArray[2] = cDegrees;

    return resultArray;
    // calcAngles() fonksiyonu calcCircumference() ve calcArea() fonksiyonunda olduğu gibi öncelikle 3 doğru oluşturur.
    // Sonrasında 3 noktası ve 3 kenarı bilinen üçgenin açılarını kosinüs teoremini kullanarak hesaplar.
    // Hesapladığı açıları A, B, C sırasında olacak şekilde bir array yapısına atar.
    // İşlem sonunda bu array yapısını geri döndürür.
}


void Triangle::setDot1(const Dot &dotObj) {
    this -> dot1 = dotObj;
}
Dot Triangle::getDot1() {
    return this -> dot1;
}


void Triangle::setDot2(const Dot &dotObj) {
    this -> dot2 = dotObj;
}
Dot Triangle::getDot2() {
    return this -> dot2;
}


void Triangle::setDot3(const Dot &dotObj) {
    this -> dot3 = dotObj;
}
Dot Triangle::getDot3() {
    return this -> dot3;
}
// Üçgen sınıfına özel setter getter fonksiyonlar.


string Triangle::toString() {

    string returnString =
            "\nUcgen noktalari:\nA:\n" + getDot1().toString() +
            "\nB:\n" + getDot2().toString() +
            "\nC:\n" + getDot3().toString();
    return returnString;
    // Üçgen nesnesinin özelliklerini string bir değere atıp bu değeri döndüren fonksiyon.
}


void Triangle::print() {
    cout << "Ucgen ozellikleri: " << toString();
    // toString() fonskiyonunu kullanarak üçgen nesnesinin özelliklerini ekrana yazdıran fonksiyon.
}