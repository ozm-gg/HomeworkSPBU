#include <string>
#ifndef SEM2TASK2_BANDIT_H
#define SEM2TASK2_BANDIT_H

class Bandit {
public:
    std::string name;
    bool isAlive;
    int horses;
    int swords;
    int rubies;
    int necklaces;
    int wives;
    int money;

    explicit Bandit(std::string name = "",
            int horses = 0,
            int swords = 0,
            int rubies = 0,
            int necklaces = 0,
            int wives = 0,
            int money = 0);

    void printInfo();

    int getWealth();

};


#endif //SEM2TASK2_BANDIT_H
