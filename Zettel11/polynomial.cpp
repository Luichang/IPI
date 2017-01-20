#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>


class Polynomial {
    std::vector<int> a_;

public:

      // Konstruktor, dem die Koeffizienten als C-Array
      // uebergeben werden koennen, z.B.:
      //
      //     Polynomial p{1, 2, 3};
    Polynomial(std::initializer_list<int> coeffs)
        : a_{ coeffs } {
    }

      // Konstruktor fuer ein Polynom vom Grad 0 (nur der konstante
      // Koeffizient ist definiert und hat den Wert 0).
    Polynomial()
        : a_{ 0 } {
    }

      // Konstruktor fuer ein Polynom vom Grad n, bei dem alle
      // Koeffizienten 0 sind. Der Fall n < 0 soll wie n == 0 behandelt
      // werden.
    Polynomial(int n)
        : a_{ 0 } {
        for (int i = 0; i < n; i++) {
            a_.push_back(0);
        }
    }

      // Grad des Polynoms (Exponent der hoechsten vorkommenden Potenz)
    int degree() const {
        return a_.size() - 1;
    }

      // lesender Zugriff auf den Koeffizienten zur Potenz i
    int operator[](int i) const {
        return a_[i];
    }

      // Lese-/Schreib-Zugriff auf den Koeffizienten zur Potenz i
    int & operator[](int i) {
        auto p = a_.begin() + i;
        return *p;
    }

      // Ausrechnen des Polynoms fuer das Argument x
    int operator()(int x) const {
        int y = 0;
        for (size_t i = 0; i < a_.size(); ++i) {
            y = y + ((*this).operator[](i) * pow(x, i));
        }
        return y;
    }

  // weitere Funktionen

    bool operator==(Polynomial p) {
        if ((*this).degree() == p.degree()) {
            for (size_t i = 0; i < a_.size(); ++i) {
                if ((*this).operator[](i) != p.operator[](i)) {
                    return false;
                }
            }
        }
        else {
            return false;
        }
        return true;
    }

    Polynomial operator+(Polynomial p) {
        Polynomial out(std::max(p.degree(), (*this).degree()));
        for (size_t i = 0; i < out.degree() + 1; i++) {
            auto a = &out.operator[](i);
            int b;
            if ((*this).degree() < i) {
                b = p.operator[](i);
            }
            else if (p.degree() < i) {
                b = (*this).operator[](i);
            }
            else {
                b = (*this).operator[](i) + p.operator[](i);
            }
            *a = b;
        }
        return out;
    }

    Polynomial operator*(Polynomial p) {
        Polynomial out((*this).degree() + p.degree());
        for (size_t i = 0; i < (*this).degree() + 1; i++) {
            for (size_t j = 0; j < p.degree() + 1; j++) {
                auto a = &out.operator[](i + j);
                int b = (*this).operator[](i) * p.operator[](j);
                *a = *a + b;
            }
        }
        return out;
    }

    Polynomial derivative() {
        Polynomial deriv((*this).degree() - 1);
        for (int i = 1; i < (*this).degree() + 1; ++i) {
            auto a = &deriv.operator[](i - 1);
            int b = (*this).operator[](i) * i;
            *a = b;
        }
        return deriv;
    }

    Polynomial derivative(int d) {
        Polynomial deriv = (*this).derivative();
        for (int i = 1; i < d; ++i) {
            deriv = deriv.derivative();
        }
        return deriv;
    }
};

inline void wait_on_enter() {
    std::string dummy;
    std::cout << "Enter to continue..." << std::endl;
    std::getline(std::cin, dummy);
}

int main() {
        // testen des Standard-Konstruktors
    Polynomial p0;
    assert(p0.degree() == 0);
    assert(p0[0] == 0);

        // testen des Konstruktors mit Gradangabe
    Polynomial pm(-1);
    assert(pm == p0);
    Polynomial p2(2);
    assert(p2.degree() == 2);

        // testen des Konstruktors mit Koeffizientenarray
    Polynomial p{ 1, 2, 3 };
    assert(p.degree() == 2);

        // testen der Werte der Koeffizienten
    assert(p2[0] == 0);
    assert(p2[1] == 0);
    assert(p2[2] == 0);

    assert(p[0] == 1);
    assert(p[1] == 2);
    assert(p[2] == 3);

        // testen, dass die Polynom fuer verschiedene Argumente x
        // korrekt ausgerechnet werden
    assert(p0(1) == 0);
    assert(p0(2) == 0);
    assert(p0(3) == 0);

    assert(p2(1) == 0);
    assert(p2(2) == 0);
    assert(p2(3) == 0);

    assert(p(1) == 6);
    assert(p(2) == 17);
    assert(p(3) == 34);
    
        // testen der Polynom-Addition
    Polynomial pa1 = p + p;
    Polynomial pa1_expected{ 2, 4, 6 };
    assert(pa1 == pa1_expected);

    Polynomial pa2 = p + Polynomial{ 3, 6 };
    Polynomial pa2_expected{ 4, 8, 3 };
    assert(pa2 == pa2_expected);
    
        // testen der Polynom-Multiplikation
    Polynomial pm1 = p * p;
    assert(pm1.degree() == 4);
    assert(pm1(2) == p(2)*p(2));
    Polynomial pm1_expected{ 1, 4, 10, 12, 9 };
    assert(pm1 == pm1_expected);
    
    Polynomial pm2 = p * Polynomial{ 2, 6 };
    assert(pm2.degree() == 3);
    Polynomial pm2_expected{ 2, 10, 18, 18 };
    assert(pm2 == pm2_expected);
    
        // testen der ersten Ableitung
    Polynomial derivative1_expected{ 2, 6 };
    assert(p.derivative() == derivative1_expected);
    assert(p.derivative(1) == derivative1_expected);
    
        // testen der zweiten bis vierten Ableitung
    Polynomial derivative2_expected{ 6 };
    Polynomial q = p.derivative(2);
    
    assert(q == derivative2_expected);
    Polynomial derivative3_expected{ 0 };
    assert(p.derivative(3) == derivative3_expected);
    assert(p.derivative(4) == derivative3_expected);

    std::cout << "Alle Tests erfolgreich!\n";
    wait_on_enter();
}

