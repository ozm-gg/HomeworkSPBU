#include <iostream>
#include "List.h"
#include "Monom.h"

void InsertPolinom(Lessons::List<Monom>& polinom){
    int deg, coef;
    int amount;
    std::cin >> amount;
    for (int i = 0; i < amount; ++i) {
        std::cin >> deg >> coef;
        Monom m{deg, coef};
        polinom.PushBack(m);
    }
}

void PrintPolinom(Lessons::List<Monom>& polinom){
    for (int i = 0; i < polinom.GetSize(); ++i) {
        std::cout<<polinom[i];
        if( i != polinom.GetSize() - 1){
            std::cout<<"+";
        }
    }
    std::cout<<std::endl;
}

bool IsPolinomsEqual(Lessons::List<Monom>& polinom1, Lessons::List<Monom>& polinom2){
    for (int i = 0; i < polinom1.GetSize(); ++i) {
        if(polinom1.CountElementWithValue(polinom1[i]) != polinom2.CountElementWithValue(polinom1[i])){
            return false;
        }
    }
    for (int i = 0; i < polinom2.GetSize(); ++i) {
        if(polinom1.CountElementWithValue(polinom2[i]) != polinom2.CountElementWithValue(polinom2[i])){
            return false;
        }
    }
    return true;
}2

int main() {
    Lessons::List<Monom> poli1;
    Lessons::List<Monom> poli2;

    InsertPolinom(poli1);
    PrintPolinom(poli1);

    InsertPolinom(poli2);
    PrintPolinom(poli2);

    if(IsPolinomsEqual(poli1, poli2)){
        std::cout<<"Equal";
    } else{
        std::cout<<"Not Equal";
    }



    return 0;
}
