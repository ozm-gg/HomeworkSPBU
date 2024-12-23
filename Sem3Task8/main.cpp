#include <iostream>
#include "Polynomial.h"
#include <vector>

std::vector<Polynomial> getHermitPolinomials(int n) {
    if (n < 3) {
        std::cerr << "too low n" << std::endl;
        exit(-1);
    }
    std::vector<Polynomial> res;
    res.emplace_back(std::vector<double>{1.0});
    res.emplace_back(std::vector<double>{0.0, 1.0});
    for (int i = 2; i < n; ++i) {
        res.emplace_back(Polynomial(std::vector<double>{0.0, 1.0}) * res[i - 1] - res[i - 2] * (i - 1));
    }
    return res;
}

int main() {
    std::vector<Polynomial> hermitPolinomials = getHermitPolinomials(11);
    for (auto &p: hermitPolinomials) {
        std::cout << p << std::endl;
    }

    return 0;
}
