#include <iostream>
#include<iomanip>
#include "Bandit.h"

Bandit::Bandit(std::string name, int horses, int swords, int rubies, int necklaces, int wives, int money) {
    this->name = name;
    this->horses = horses;
    this->isAlive = true;
    this->swords = swords;
    this->rubies = rubies;
    this->necklaces = necklaces;
    this->wives = wives;
    this->money = money;
}

int Bandit::getWealth() {
    return 500 * horses + 100 * swords + 50 * rubies + 10 * necklaces - 200 * wives + money;
}

void Bandit::printInfo() {
    std::string alive = isAlive ? "да" : "нет";
    std::cout << std::left << std::setw(12) << name << std::left << std::setw(6) << alive << std::left << std::setw(6)
              << horses << std::left << std::setw(6)
              << swords << std::left << std::setw(6) << rubies << std::left << std::setw(6)
              << necklaces << std::left << std::setw(6) << wives << std::left << std::setw(10) << money << std::left
              << std::setw(10) << getWealth() << std::endl;
}
