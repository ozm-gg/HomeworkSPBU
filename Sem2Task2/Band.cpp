#include <iostream>
#include <iomanip>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Bandit.h"
#include "Band.h"

#include <utility>

#define WIDTH 2000
#define HEIGHT 1200

Band::Band() {
    this->capacity = 10;
    this->size = 0;
    this->band = new Bandit[capacity];
    this->aliveCount = 0;
    this->horses = 0;
    this->swords = 0;
    this->rubies = 0;
    this->necklaces = 0;
    this->wives = 0;
    this->money = 0;
    this->wealth = 0;
    this->richIndex = -1;
    this->richestWealth = -2000;
}

Bandit &Band::operator[](int i) const {
    return this->band[i];
}

void Band::addBandit(Bandit bandit) {
    if (size < capacity) {
        this->band[size] = std::move(bandit);
        size++;
    } else {
        this->capacity *= 2;
        Bandit *tmp = new Bandit[capacity];
        for (int i = 0; i < size; ++i) {
            tmp[i] = std::move(this->band[i]);
        }
        tmp[size] = std::move(bandit);
        size++;
        delete[] this->band;
        this->band = tmp;
    }
    this->horses += bandit.horses;
    this->swords += bandit.swords;
    this->rubies += bandit.rubies;
    this->necklaces += bandit.necklaces;
    this->wives += bandit.wives;
    this->money += bandit.money;
    this->wealth += bandit.getWealth();
    this->aliveCount++;
    if (bandit.getWealth() > richestWealth) {
        richestWealth = bandit.getWealth();
        richIndex = size - 1;
    }

}

void Band::killBandit(std::string name) {
    for (int i = 0; i < size; ++i) {
        if (name == band[i].name and band[i].isAlive) {
            band[i].isAlive = false;
            this->horses -= band[i].horses;
            this->swords -= band[i].swords;
            this->rubies -= band[i].rubies;
            this->necklaces -= band[i].necklaces;
            this->wives -= band[i].wives;
            this->money -= band[i].money;
            this->wealth -= band[i].getWealth();
            break;
        }
    }
    this->aliveCount--;
    this->richestWealth = -2000;
    this->richIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (richestWealth < band[i].getWealth() and band[i].isAlive) {
            richIndex = i;
            richestWealth = band[i].getWealth();
        }
    }
}

void Band::printRichest() const {
    band[richIndex].printInfo();
}

void Band::printBandInfo(bool withDead) const {
    for (int i = 0; i < size; ++i) {
        if (!withDead) {
            if (band[i].isAlive) {
                band[i].printInfo();
            }
        } else {
            band[i].printInfo();
        }
    }
    std::cout << std::left << std::setw(18) << "Итого:" << std::left << std::setw(6) << horses << std::left
              << std::setw(6) << swords << std::left << std::setw(6) << rubies << std::left << std::setw(6) << necklaces
              << std::left << std::setw(6) << wives << std::left << std::setw(10)
              << money << std::left << std::setw(10) << wealth << std::endl;

}

void Band::printByName(std::string name) const {
    for (int i = 0; i < size; ++i) {
        if (name == band[i].name) {
            band[i].printInfo();
        }
    }
}

void Band::render() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Graphics");

    srand(time(0));
    sf::Color colors[aliveCount];
    for (int i = 0; i < aliveCount; ++i) {
        colors[i] = sf::Color(rand()%256, rand()%256 ,rand()%256);
    }

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::White);

        sf::RectangleShape hist;
        sf::Vector2f pos(WIDTH/8, 3*HEIGHT/4);
        sf::Text name;
        name.setFillColor(sf::Color::Black);
        sf::Font font;
        font.loadFromFile("C:\\CLionProjects\\Sem2Task2\\Stengazeta-Regular_5.ttf");
        name.setFont(font);
        hist.setFillColor(sf::Color::Red);
        name.rotate(90);
        int histWidth = 20;
        int histGap = 5;
        float* relativeValues = new float[aliveCount];
        for (int i = 0, j = 0; i < size; ++i) {
            if(band[i].isAlive){
                float histHeight = static_cast<float>(band[i].getWealth())/static_cast<float>(richestWealth) * HEIGHT/2;
                hist.setSize(sf::Vector2f(histWidth, histHeight));
                hist.setOrigin(0, histHeight);
                hist.setPosition(pos);
                pos += sf::Vector2f(histWidth + histGap, 0);
                name.setPosition(pos);
                name.setString(band[i].name);
                window.draw(hist);
                window.draw(name);
                relativeValues[j] = static_cast<float>(band[i].getWealth())/wealth;
                j++;
            }
        }

        int vertexCount = 1000;
        int radius = 300;
        sf::VertexArray diagram(sf::TriangleFan, vertexCount);

        sf::Color color = colors[0];
        float shift = 0;
        diagram[0].position = sf::Vector2f(3*WIDTH/4, HEIGHT/2);
        for(int i = 1, j = 0; i < vertexCount; ++i){
            double angle = 2*M_PI / vertexCount * i;
            diagram[i].position = sf::Vector2f (cos(angle) * radius,sin(angle)* radius)+diagram[0].position;
            if(static_cast<float>(i)/static_cast<float>(vertexCount) - shift > relativeValues[j]) {
                j++;
                color = colors[j];
                shift = static_cast<float>(i) / static_cast<float>(vertexCount);
            }
            diagram[i].color = color;
        }
        delete [] relativeValues;
        diagram[vertexCount-1].position = diagram[1].position;
        window.draw((diagram));


        window.display();
    }
}
