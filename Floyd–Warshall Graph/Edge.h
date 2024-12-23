#include <SFML/Graphics.hpp>
#ifndef FLOYDWARSHALL_GRAPH_EDGE_H
#define FLOYDWARSHALL_GRAPH_EDGE_H


class Edge : public sf::Drawable
{
private:
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;
public:
    Edge(const sf::Vector2f& begin, const sf::Vector2f& end, const sf::Color& color);
    sf::Vector2f Point1,Point2;
    sf::Color Colour;
};


#endif //FLOYDWARSHALL_GRAPH_EDGE_H
