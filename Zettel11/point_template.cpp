#include <string>
#include <iostream>
#include <cassert>


template <typename CoordinateType>
class Point {
private:
  // die Koordinaten des Punktes
    //typedef double CoordinateType;
    CoordinateType x_;
    CoordinateType y_;

public:

  // Standardkonstruktor: initialisiere Punkt (0,0)
    Point()
        : x_(0.0)
        , y_(0.0) {
    }

   // Konstruktor mit zwei Koordinaten: initialisiere Punkt (x,y)
    Point(CoordinateType x, CoordinateType y)
        : x_(x)
        , y_(y) {
    }

   // Getter-Funktionen fuer die Koordinaten
    CoordinateType x() const {
        return (*this).x_;
    }

    CoordinateType y() const {
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
        Point res((*this).y(), (*this).x());
        return res;
    }

    // erzeuge neuen Punkt, der um den Vektor v verschoben ist
    Point translate(Point const & v) const {
        Point res((*this).x() + v.x(), (*this).y() + v.y());
        return res;
    }
};

// wandle den Punkt in einen String der Form "[x, y]"
template <typename CoordinateType>
std::string to_string(Point<CoordinateType> const & p) {
    return "[" + std::to_string(p.x()) + ", " + std::to_string(p.y()) + "]";
}

template <typename CoordinateType>
Point<CoordinateType> operator+(Point<CoordinateType> p1, Point<CoordinateType> p2) {
    Point<CoordinateType> res(p1.x() + p2.x(), p1.y() + p2.y());
    return res;
}

template <typename CoordinateType>
Point<CoordinateType> operator-(Point<CoordinateType> p1, Point<CoordinateType> p2) {
    Point<CoordinateType> res(p1.x() - p2.x(), p1.y() - p2.y());
    return res;
}

template <typename CoordinateType>
Point<CoordinateType> operator-(Point<CoordinateType> p) {
    Point<CoordinateType> res(-p.x(), -p.y());
    return res;
}

template <typename CoordinateType>
Point<CoordinateType> operator*(Point<CoordinateType> p1, Point<CoordinateType> p2) {
    Point<CoordinateType> res(p1.x()*p2.x(), p1.y()*p2.y());
    return res;
}

template <typename CoordinateType>
Point<CoordinateType> operator*(CoordinateType s, Point<CoordinateType> p) {
    Point<CoordinateType> res(s*p.x(), s*p.y());
    return res;
}

template <typename CoordinateType>
Point<CoordinateType> operator*(Point<CoordinateType> p, CoordinateType s) {
    Point<CoordinateType> res(p.x()*s, p.y()*s);
    return res;
}

template <typename CoordinateType>
Point<CoordinateType> operator/(Point<CoordinateType> p1, Point<CoordinateType> p2) {
    Point<CoordinateType> res(p1.x() / p2.x(), p1.y() / p2.y());
    return res;
}

template <typename CoordinateType>
Point<CoordinateType> operator/(Point<CoordinateType> p, CoordinateType d) {
    Point<CoordinateType> res(p.x() / d, p.y() / d);
    return res;
}

void test_Point_double() {
    typedef Point<double> P; // neuer kurzer Name für 'Point'

    P pp;
    assert(pp.x() == 0);
    assert(pp.y() == 0);

    // fuegen Sie Tests hinzu

    P p(2, 3.5);
    P pa1 = p + p;
    P pa1_expected(4, 7);
    assert(pa1 == pa1_expected);

    P pa2 = p + P(3.2, 6.7);
    P pa2_expected(5.2, 10.2);
    assert(pa2 == pa2_expected);

    P pm1 = p * p;
    P pm1_expected(4, 12.25);
    assert(pm1 == pm1_expected);

    P pm2 = p * P(2.5, 6.3);
    P pm2_expected(5, 22.05);
    assert(pm2 == pm2_expected);

    std::cout << "Alle Tests erfolgreich.\n";
}

void test_Point_int() {
    typedef Point<int> P; // neuer kurzer Name für 'Point'

    P pp;
    assert(pp.x() == 0);
    assert(pp.y() == 0);

    // fuegen Sie Tests hinzu

    P p(2, 3);
    P pa1 = p + p;
    P pa1_expected(4, 6);
    assert(pa1 == pa1_expected);

    P pa2 = p + P(3, 6);
    P pa2_expected(5, 9);
    assert(pa2 == pa2_expected);

    P pm1 = p * p;
    P pm1_expected(4, 9);
    assert(pm1 == pm1_expected);

    P pm2 = p * P(3, 8);
    P pm2_expected(6, 24);
    assert(pm2 == pm2_expected);

    std::cout << "Alle Tests erfolgreich.\n";
}

inline void wait_on_enter() {
    std::string dummy;
    std::cout << "Enter to continue..." << std::endl;
    std::getline(std::cin, dummy);
}

int main() {
    test_Point_double();
    test_Point_int();
    wait_on_enter();
}
