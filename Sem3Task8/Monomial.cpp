#include "Monomial.h"

Monomial::Monomial( double coef, unsigned int degree)
        : degree(degree), coef(coef) {

}

Monomial Monomial::operator*(const Monomial &other) {
    return Monomial(this->coef * other.coef, this->degree + other.degree);
}

Monomial Monomial::operator*(const double &value) {
    return Monomial( this->coef * value , this->degree);
}

Monomial::Monomial(): degree(0), coef(0)  {}

std::ostream &operator<<(std::ostream &stream, const Monomial &obj) {
    stream << obj.coef;
    if(obj.degree == 1){
        stream << "*X";
    }else if(obj.degree > 1){
        stream << "*X^"<<obj.degree;
    }
    return stream;
}

bool Monomial::operator==(Monomial other) const {
    return this->degree == other.degree and this->coef == other.coef;
}


