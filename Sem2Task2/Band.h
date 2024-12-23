#include "Bandit.h"

#ifndef SEM2TASK2_BAND_H
#define SEM2TASK2_BAND_H


class Band {
public:
    Bandit *band;
    int size;
    int capacity;
    int aliveCount;
    int horses;
    int swords;
    int rubies;
    int necklaces;
    int wives;
    int money;
    int wealth;
    int richIndex;
    int richestWealth;

    Band();

    Bandit &operator[](int i) const;

    void addBandit(Bandit bandit);

    void killBandit(std::string name);

    void printRichest() const;

    void printBandInfo(bool withDead = true) const;

    void printByName(std::string name) const;

    void render();
};


#endif //SEM2TASK2_BAND_H
