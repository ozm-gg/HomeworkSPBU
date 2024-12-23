//
// Created by дима on 06.03.2024.
//

#ifndef SEM2TASK4_MONOM_H
#define SEM2TASK4_MONOM_H
class Monom{
public:
    int degree;
    int coef;

};
bool operator==(const Monom& monom1, const Monom& monom2){
    if(monom1.coef == monom2.coef and monom1.degree == monom2.degree) return true;
    return false;
}
std::ostream& operator<<(std::ostream& stream, const Monom& monom)
{
    switch (monom.degree) {
        case 0:
            stream << monom.coef;
            break;
        case 1:
            stream << monom.coef <<"x";
            break;
        default:
            stream << monom.coef <<"x^"<< monom.degree;
            break;
    }

    return stream;
}
#endif //SEM2TASK4_MONOM_H
