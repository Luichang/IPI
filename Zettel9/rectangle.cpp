#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

/////////////////////////////////////////////////
// die 2-dimensionale Punkt-Klasse aus der Vorlesung
class Point
{
    // die Koordinaten des Punktes
    double x_;
    double y_;

  public:

    // Standardkonstruktor: initialisiere Punkt (0,0)
      Point()
          : x_(0.0)
          , y_(0.0) {
      }

    // Konstruktor mit zwei Koordinaten: initialisiere Punkt (x,y)
    Point(double x, double y)
        : x_(x)
        , y_(y) {
    }

    // Getter-Funktionen fuer die Koordinaten
    double x() const {
        return (*this).x_;
    }

    double y() const {
        return (*this).y_;
    }

    // teste ob zwei Punkte gleich sind
    bool operator==(Point const & other) const {
        return (*this).x() == other.x() && (*this).y() == other.y();
    }

    // teste ob zwei Punkte ungleich sind
    bool operator!=(Point const & other) const {
        return (*this).x() != other.x() || (*this).y() != other.y();
    }

    // erzeuge neuen Punkt, desssen x- und y-Koordinate
    // vertauscht sind
    Point transpose() const {
        Point res((*this).y(), (*this).x()); // setting the x value to the original y and the y value to the original x
        return res;
    }

    // erzeuge neuen Punkt, der um den Vektor v verschoben ist
    Point translate(Point const & v) const {
        Point res((*this).x() + v.x(), (*this).y() + v.y()); // adding the x of the received point to the original point
        return res;                                          // same with the y
    }
};

// wandle den Punkt in einen String der Form "[x, y]"
std::string to_string(Point const & p) {
    return "[" + std::to_string(p.x()) 
        + ", " + std::to_string(p.y())      // using a basic display return for the string to follow the form of [x, y]
        + "]";
}

/////////////////////////////////////////////////
// Implementieren Sie die Rectangle-Klasse.
class Rectangle {
    Point p0_; // linke untere Ecke
    Point p1_; // rechte obere Ecke

public:

    // Implementieren Sie die folgenden Konstruktoren.
    Rectangle() { // this function does not need to be edited, seeing as every point in initialized in 0.0, 0.0
    }

    Rectangle(Point const & p1) { // we are translating the point to the inserted point to have the proper size of rectangle
        p1_ = p1_.translate(p1);
    }

    Rectangle(Point const & p0, Point const & p1) { // in this case we transpose both corners
        p0_ = p0_.translate(p0);
        p1_ = p1_.translate(p1);
    }

    // read-only Getter-Funktionen fuer die Member-Variablen
    Point const & p0() const {
        return (*this).p0_;
    }

    Point const & p1() const {
        return (*this).p1_;
    }

    // Implementieren Sie die folgenden Getter-Funktionen.
    double x0() const { // linke x-Koordinate
        return (*this).p0_.x();
    }

    double x1() const { // rechte x-Koordinate
        return (*this).p1_.x();
    }

    double y0() const { // untere y-Koordinate
        return (*this).p0_.y();
    }

    double y1() const { // obere  y-Koordinate
        return (*this).p1_.y();
    }

    double width() const { // Breite
        return (*this).x1() - (*this).x0();
    }

    double height() const { // Hoehe
        return (*this).y1() - (*this).y0();
    }

    // Implementieren Sie eine Funktion, die genau dann 'true'
    // zurueckgibt, wenn das Rechteck nicht ungueltig ist.
    bool is_valid() const { // this funciton checks to see if the hight and width are positive
        return (((*this).height() >= 0) && ((*this).width() >= 0) );
    }

    // Implementieren Sie eine Funktion, die die Flaeche des
    // Rechtecks zurueckgibt, bzw. -1.0, wenn das Rechteck
    // ungueltig ist.
    double area() const {  // returning height * width
        if ((*this).is_valid()) {
            return (*this).height() * (*this).width();
        }
        else if ((*this).height() < 0 || (*this).width() < 0){   // in the case we had negative values the result was to be
            return -1.0;                                         // -1
        }
        else {                                                   // in the case that we just received a lign the return was
            return 0.0;                                          // supposed to be 0
        }                 
    }

    // Implementieren Sie eine Funktion, die ein neues Rechteck
    // zurueckgibt, bei dem die x- und y-Koordinaten vertauscht sind.
    Rectangle transpose() const {
        return Rectangle(p0_.transpose(), p1_.transpose());   // switching around both the top right coordinates with 
    }                                                         // eachother and bottom left

    // Implementieren Sie eine Funktion, die ein neues Rechteck
    // zurueckgibt, das um den Vektor v verschoben ist.
    Rectangle translate(Point const & v) const {
        return Rectangle(Point((*this).p0_.translate(v)), Point((*this).p1_.translate(v))); // using the Point functions
    }                                                                                       // to move the rectangle around

    // Implementieren Sie eine Funktion, die genau dann 'true'
    // zurueckgibt, wenn der Punkt p im Rechteck (*this) enthalten
    // ist. Wenn (*this) ungueltig ist, soll 'false' zurueckgegeben
    // werden.
    bool contains(Point const & p) const { // point
        if ((*this).x0() <= p.x() &&
            (*this).y0() <= p.y() &&
            (*this).x1() >= p.x() &&
            (*this).y1() >= p.y()) {
            return true;               // if the given point has an x greater x than the left point and smaller x than the 
        }
        return false;                  // right + if the point has a y greater than the bottom point of the rectangle and
    }                                  // smaller y than the top the return will be true

    // Implementieren Sie eine Funktion, die genau dann 'true'
    // zurueckgibt, wenn das Rechteck r im Rechteck (*this) enthalten
    // ist. Wenn (*this) oder r ungueltig sind, soll 'false' zurueckgegeben
    // werden.
    bool contains(Rectangle const & r) const { // rectangle
        if ((*this).x0() <= r.x0() && (*this).y0() <= r.y0() && (*this).x1() >= r.x1() && (*this).y1() >= r.y1())
            return true;             // same as with the point only that each corner will be checked from both to ensure
        return false;                // all of the second rectangle is in the first
    }
};

// Implementieren Sie eine Funktion, die das Rechteck
// in einen String der Form "[x0:x1, y0:y1]" umwandelt.
std::string to_string(Rectangle const & r) {
    std::string out;                         // getting all 4 coordinates and displaying them the way the assignment wants
    out = "[" + std::to_string(r.x0())       
        + ":" + std::to_string(r.x1())       
        + ", " + std::to_string(r.y0()) 
        + ":" + std::to_string(r.y1()) 
        + "]";
    return out;
}

// Implementieren Sie eine Funktion, die das kleinste Rechteck
// zurueckgibt, das r1 und r2 enthaelt.
Rectangle rectangle_union(Rectangle const & r1, Rectangle const & r2) {  
    return Rectangle(Point(std::min(r1.x0(), r2.x0()), std::min(r1.y0(), r2.y0())), // taking the smallest botom left
        Point(std::max(r1.x1(), r2.x1()), std::max(r1.y1(), r2.y1())));             // and largest top right points and
}                                                                                   // creating a new Rectangle

// Implementieren Sie eine Funktion, die den Durchschnitt
// der Rechtecke r1 und r2 zerueckgibt, oder ein beliebiges
// ungueltiges Rechteck, falls r1 und r2 nicht ueberlappen.
Rectangle rectangle_intersection(Rectangle const & r1, Rectangle const & r2) { 
    Point graterp0(std::min(r1.x0(), r2.x0()), std::max(r1.y0(), r2.y0()));
    Point lesserp1(std::max(r1.x1(), r2.x1()), std::min(r1.y1(), r2.y1()));
    if (r1.contains(graterp0) ||     // if either rectangle contains any points of the other rectangle
        r1.contains(lesserp1) || 
        r2.contains(graterp0) || 
        r2.contains(lesserp1)) {
        return Rectangle(graterp0, lesserp1);
    }
    return Rectangle(Point(-1, -1)); // creating a dummy rectangle for the cases where there is no intersection;
}

// Implementieren Sie Tests fuer die Rectangle-Klasse.
void testRectangle() {
    /*Rectangle r0(Point(3.0, 5.0));

    assert(r0.p0() == Point(0.0, 0.0));
    assert(r0.p1() == Point(3.0, 5.0));

    Rectangle r(Point(1.0, 2.0), Point(3.0, 5.0));

    assert(r.x0() == 1.0);*/
    // Fuegen Sie weitere Tests entsprechend der Aufgabe hinzu
    
    for (double i = 1; i < 7; i++) {           // creating a for loop for all the tests...
        Rectangle iterated1(Point(i * 2, i * 9));
        Rectangle iterated2(Point(i + 1, i + 2), Point(i * 4, i * 15));
        Rectangle iterated3 = rectangle_intersection(iterated1, iterated2);
        Rectangle iterated4 = rectangle_union(iterated1, iterated2);
        Point p(iterated3.x0() + 1, iterated3.y1() - 1);
        assert(iterated3.contains(p));

        assert(iterated4.contains(iterated1) && iterated4.contains(iterated2));
        Point moving(i * 3, i + 2);
        Rectangle iterated5 = iterated4.translate(moving);
        assert(iterated5.p0() == iterated4.p0().translate(moving) && iterated5.p1() == iterated4.p1().translate(moving));

        assert(iterated1.p0() == Point(0.0, 0.0));
        assert(iterated1.p1() == Point(i * 2, i * 9));
        assert(to_string(iterated1) == "[" + std::to_string(iterated1.x0())
            + ":" + std::to_string(iterated1.x1())
            + ", " + std::to_string(iterated1.y0())
            + ":" + std::to_string(iterated1.y1())
            + "]");
        assert(iterated1.height() == i * 9);
        assert(iterated1.width() == i * 2);
        assert(iterated1.area() == (i * 9) * (i * 2));

        assert(iterated2.p1() == Point(i * 4, i * 15));
        assert(iterated2.p0() == Point(i + 1, i + 2));
        iterated2 = iterated2.transpose();
        assert(iterated2.p1() == Point(i * 15, i * 4));
        assert(iterated2.p0() == Point(i + 2, i + 1));

    }
    Rectangle twoTrue(Point (5, 3), Point(9, 6));
    Rectangle oneTrue(Point(7, 4), Point(15, 5));
    Rectangle oneFalse(Point(5, 3), Point(3, 6));
    Rectangle twoFalse(Point(2, 5), Point(4, 2));
    assert(oneTrue.is_valid());
    assert(!oneFalse.is_valid());
    assert(twoTrue.is_valid());
    assert(!twoFalse.is_valid());

    std::cout << "alle Rectangle-Tests erfolgreich\n";
}

inline void wait_on_enter() {  // started using visual studio which terminates the terminal after the program
    std::string dummy;         // finished running
    std::cout << "Enter to continue..." << std::endl;
    std::getline(std::cin, dummy);
}

int main() {
    testRectangle();
    wait_on_enter();
}