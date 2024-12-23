//
// Created by дима on 15.02.2024.
//
#include <cmath>
#include "Edge.h"

void Edge::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    int triangleRad = 10;

    sf::RectangleShape line;
    sf::CircleShape triangle(triangleRad, 3);


    sf::Vector2f vec = Point2 - Point1;
    double vecLen = sqrt(vec.x * vec.x + vec.y * vec.y);
    double angle = vec.y >= 0 ? -acos(vec.x / vecLen) * 180 / M_PI : acos(vec.x / vecLen) * 180 / M_PI;
    double lineThick = 4;

    triangle.setOrigin(triangleRad, triangleRad);
    triangle.setPosition(Point2);
    triangle.rotate(-angle + 90);
    triangle.setFillColor(Colour);
    line.rotate(-angle);
    line.setOrigin(0, lineThick / 2);
    line.setSize(sf::Vector2f(vecLen, lineThick));
    line.setPosition(Point1);
    line.setFillColor(Colour);
    target.draw(line);
    target.draw(triangle);
}

Edge::Edge(const sf::Vector2f &begin, const sf::Vector2f &end, const sf::Color &color = sf::Color::Black) {
    this->Point1 = begin;
    this->Point2 = end;
    this->Colour = color;
}
