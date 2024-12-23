#include <ostream>

#ifndef SEM3TASK8_MONOMIAL_H
#define SEM3TASK8_MONOMIAL_H


class Monomial {
public:
    unsigned int degree;
    double coef;
    Monomial( double coef, unsigned int degree);
    Monomial();
    bool operator==(Monomial other) const;
    Monomial operator *(const Monomial& other);
    Monomial operator *(const double& value);
    friend std::ostream& operator<<(std::ostream& stream, const Monomial& obj);
};


#endif //SEM3TASK8_MONOMIAL_H
