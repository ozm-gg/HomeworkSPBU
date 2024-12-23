#include "Polynomial.h"

Polynomial::Polynomial(const std::vector<double> coefs): monomials(MAX_NUM_MONOMIALS), degree(0) {
    if(coefs.size() > MAX_NUM_MONOMIALS){
        exit(-1);
    }
    for (int i = 0; i < MAX_NUM_MONOMIALS; ++i) {
        monomials[i] = Monomial(i >= coefs.size() ? 0.0 :coefs[i] , i);
        if(monomials[i].coef){
            degree = i;
        }
    }
}

Polynomial Polynomial::operator*(Polynomial other) {
    std::vector<double> new_coefs(MAX_NUM_MONOMIALS);
    for (int i = 0; i < MAX_NUM_MONOMIALS; ++i) {
        for (int j = 0; j <= i; ++j) {
            new_coefs[i] += this->monomials[j].coef * other.monomials[i - j].coef;
        }
    }
    return Polynomial(new_coefs);
}

Polynomial Polynomial::operator*(double value) {
    std::vector<double> new_coefs;
    for (int i = 0; i < MAX_NUM_MONOMIALS; ++i) {
        new_coefs.emplace_back(this->monomials[i].coef * value);
    }
    return Polynomial(new_coefs);
}

Polynomial Polynomial::operator*(Monomial other) {
    std::vector<double> coefs;
    for (int i = 0; i < other.degree; ++i) {
        coefs.emplace_back(0);
    }
    coefs.emplace_back(other.coef);
    Polynomial otherPoly = Polynomial(coefs);
    return *this * otherPoly;
}

Polynomial Polynomial::operator+(Polynomial other) {
    std::vector<double> new_coefs;
    for (int i = 0; i < MAX_NUM_MONOMIALS; ++i) {
        new_coefs.emplace_back(this->monomials[i].coef + other.monomials[i].coef);
    }
    return Polynomial(new_coefs);
}

Polynomial Polynomial::operator-(Polynomial other) {
    return *this + (other * -1.0);
}

std::ostream & operator<<(std::ostream &stream, const Polynomial& obj) {
    for (int i = 0; i < obj.degree; ++i) {
        if(obj.monomials[i].coef !=0){
            stream << obj.monomials[i] << " + ";
        }
    }
    stream << obj.monomials[obj.degree];
    return stream;
}

bool Polynomial::operator==(Polynomial other) const {
    return this->monomials == other.monomials;
}

