#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include "Band.h"
#include "Bandit.h"






int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    std::vector<std::string> names;
    std::ifstream in("C:\\CLionProjects\\Sem2Task2\\names.txt");

    if (in.is_open()) {
        std::string line;
        while (std::getline(in, line)) {
            names.push_back(line);
            //std::cout<<line<<std::endl;
        }
    }
    in.close();

    Band band;
    for (int i = 0; i < 5; ++i) {
        band.addBandit(Bandit(names[rand() % names.size()],
                              rand() % 10,
                              rand() % 10,
                              rand() % 40,
                              rand() % 20,
                              rand() % 5,
                              rand() % 10000));
    }



    int input;
    std::string name;
    int horses;
    int swords;
    int rubies;
    int necklaces;
    int wives;
    int money;

    while (std::cin >> input) {
        /*std::cout<<"1 - Вывести информацию о банде\n"
                   "2 - Вывести информацию о живых\n"*/
        switch (input) {
            case 0:
                return 0;
            case 1:
                band.printBandInfo();
                break;
            case 2:
                band.printBandInfo(false);
                break;
            case 3:
                band.printRichest();
                break;
            case 4:
                std::cin >> name;
                band.killBandit(name);
                break;
            case 5:
                std::cin >> name >> horses >> swords >> rubies >> necklaces >> wives >> money;
                band.addBandit(Bandit(name, horses, swords, rubies, necklaces, wives, money));
                break;
            case 6:
                std::cin >> name;
                band.printByName(name);
                break;
            case 7:
                band.render();
                break;


        }
    }

}
