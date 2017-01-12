#include <string>
#include <iostream>
#include <cassert>

class Point
{
  private:
    // die Koordinaten des Punktes
    double x_;
    double y_;

  public:

    // Standardkonstruktor: initialisiere Punkt (0,0)
    Point()
    : x_(0.0)
    , y_(0.0)
    {}

    // Konstruktor mit zwei Koordinaten: initialisiere Punkt (x,y)
    Point(double x, double y)
    : x_(x)
    , y_(y)
    {}

    // Getter-Funktionen fuer die Koordinaten
    double x() const
    {
        return (*this).x_;
    }

    double y() const
    {
        return (*this).y_;
    }

    // teste ob zwei Punkte gleich sind
    bool operator==(Point const & other) const
    {
        return (*this).x() == other.x() && (*this).y() == other.y();
    }

    // teste ob zwei Punkte ungleich sind
    bool operator!=(Point const & other) const
    {
        return (*this).x() != other.x() || (*this).y() != other.y();
    }

    // erzeuge neuen Punkt, desssen x- und y-Koordinate
    // vertauscht sind
    Point transpose() const
    {
        Point res((*this).y(), (*this).x());
        return res;
    }

    // erzeuge neuen Punkt, der um den Vektor v verschoben ist
    Point translate(Point const & v) const
    {
        Point res((*this).x() + v.x(), (*this).y() + v.y());
        return res;
    }

};

// wandle den Punkt in einen String der Form "[x, y]"
std::string to_string(Point const & p)
{
    return "[" + std::to_string(p.x()) + ", " + std::to_string(p.y()) + "]";
}

// Implementieren Sie hier die arithmetischen Operationen
Point operator+(Point p1, Point p2) {
    double newX = p1.x() + p2.x();
    double newY = p1.y() + p2.y();
    return Point(newX, newY);
}

Point operator-(Point p1, Point p2) {
    double newX = p1.x() - p2.x();
    double newY = p1.y() - p2.y();
    return Point(newX, newY);
}

Point operator*(Point p1, Point p2) {
    double newX = p1.x() * p2.x();
    double newY = p1.y() * p2.y();
    return Point(newX, newY);
}

Point operator/(Point p1, Point p2) {
    double newX = p1.x() / p2.x();
    double newY = p1.y() / p2.y();
    return Point(newX, newY);
}

Point operator*(Point p, double s) {
    double newX = p.x() * s;
    double newY = p.y() * s;
    return Point(newX, newY);
}

Point operator*(double s, Point p) {
    double newX = p.x() * s;
    double newY = p.y() * s;
    return Point(newX, newY);
}

Point operator/(Point p, double s) {
    double newX = p.x() / s;
    double newY = p.y() / s;
    return Point(newX, newY);
}

Point operator-(Point p) {
    double newX = -p.x();
    double newY = -p.y();
    return Point(newX, newY);
}

void test_Point()
{
    typedef Point P; // neuer kurzer Name für 'Point'

    P p;
    assert(p.x() == 0);
    assert(p.y() == 0);

    // fuegen Sie Tests der arithmetischen Operationen hinzu
    P p1(2.0, 3.0), p2(32.5, 1.34), p3(5.12, 12.5), q1(4.0, 5.0), q2(2.53, 21.3), q3(3.32, 4.12);
    double sth = 1;
    P add1 = p1 + q1;
    P add2 = p2 + q2;
    P add3 = p3 + q3;
    P sub1 = p1 - q1;
    P sub2 = p2 - q2;
    P sub3 = p3 - q3;
    P mul1 = p1 * q1;
    P mul2 = p2 * q2;
    P mul3 = p3 * q3;
    P div1 = p1 / q1;
    P div2 = p2 / q2;
    P div3 = p3 / q3;
    P scalMul1 = p1 * sth;
    P scalMul2 = p2 * sth;
    P scalMul3 = p3 * sth;
    P scalMul4 = sth * p1;
    P scalMul5 = sth * p2;
    P scalMul6 = sth * p3;
    P scalDiv1 = p1 / sth;
    P negate = -p1;
    
    assert(add1 == P(p1.x() + q1.x(), p1.y() + q1.y()));
    assert(add2 == P(p2.x() + q2.x(), p2.y() + q2.y()));
    assert(add3 == P(p3.x() + q3.x(), p3.y() + q3.y()));
    assert(sub1 == P(p1.x() - q1.x(), p1.y() - q1.y()));
    assert(sub2 == P(p2.x() - q2.x(), p2.y() - q2.y()));
    assert(sub3 == P(p3.x() - q3.x(), p3.y() - q3.y()));
    assert(mul1 == P(p1.x() * q1.x(), p1.y() * q1.y()));
    assert(mul2 == P(p2.x() * q2.x(), p2.y() * q2.y()));
    assert(mul3 == P(p3.x() * q3.x(), p3.y() * q3.y()));
    assert(div1 == P(p1.x() / q1.x(), p1.y() / q1.y()));
    assert(div2 == P(p2.x() / q2.x(), p2.y() / q2.y()));
    assert(div3 == P(p3.x() / q3.x(), p3.y() / q3.y()));
    assert(scalMul1 == P(p1.x() * sth, p1.y() * sth));
    assert(scalMul2 == P(p2.x() * sth, p2.y() * sth));
    assert(scalMul3 == P(p3.x() * sth, p3.y() * sth));
    assert(scalMul1 == scalMul4);
    assert(scalMul2 == scalMul5);
    assert(scalMul3 == scalMul6);
    assert(scalDiv1 == P(p1.x() / sth, p1.y() / sth));
    assert(negate == P(-p1.x(), -p1.y()));

    std::cout << "Alle Tests erfolgreich.\n";
}

inline void wait_on_enter() {  
    std::string dummy;
    std::cout << "Enter to continue..." << std::endl;
    std::getline(std::cin, dummy);
}

int main()
{
    test_Point();
    wait_on_enter();
}
