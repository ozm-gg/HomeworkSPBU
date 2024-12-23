#include <vector>
#include <ostream>
#include "Monomial.h"

#ifndef SEM3TASK8_POLYNOMIAL_H
#define SEM3TASK8_POLYNOMIAL_H
#define MAX_NUM_MONOMIALS 256

class Polynomial {
public:
    unsigned int degree;
    std::vector<Monomial> monomials;

    explicit Polynomial(std::vector<double> coefs);

    bool operator==(Polynomial other) const;

    Polynomial operator*(Polynomial other);

    Polynomial operator*(double value);

    Polynomial operator*(Monomial other);

    Polynomial operator+(Polynomial other);

    Polynomial operator-(Polynomial other);

    friend std::ostream& operator<<(std::ostream& stream, const Polynomial& obj);
};


#endif //SEM3TASK8_POLYNOMIAL_H
