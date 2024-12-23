#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <limits>
#include "Edge.h"

#define WIDTH 1500
#define HEIGHT 1000
#define VERTEX_RADIUS 400

void alg(std::vector<std::vector<int>> matrix, std::vector<std::vector<int>>& Path) {
    for (int k = 0; k < matrix.size(); ++k) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                if( matrix[i][k] + matrix[k][j] < matrix[i][j] || matrix[i][j] == 0 || matrix[i][j] == std::numeric_limits<int>::max() - 5000){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    Path[i][j] = k;

                }
            }
        }
        for (int l = 0; l < matrix.size(); ++l) {
            for (int m = 0; m <  matrix.size(); ++m) {
                std::cout<<Path[l][m]<<"\t";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
}

void createPath(std::vector<int>& p, const std::vector<std::vector<int>>& Path, int i, int j){
    if(Path[i][j] == -1){
        return;
    }
    createPath(p, Path, i, Path[i][j]);
    p.push_back(Path[i][j]);
    createPath(p, Path, Path[i][j], j);
}

std::vector<int> getPath(const std::vector<std::vector<int>>& Path, int i, int j){
    std::vector<int> p;
    p.push_back(i),
    createPath(p, Path, i, j);
    p.push_back(j);
    return p;
}


int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8.0;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Graph", sf::Style::Close, settings);
    window.setVerticalSyncEnabled(true);


    int inf = 5000;
    std::vector<std::vector<int>> matrix{
            {0,      inf,   22,      8,      1,      1,      inf},
            {inf,   0,      inf,    4,      inf,    1,      inf},
            {22,     inf,    0,      1,      inf,    inf,    inf},
            {8,     4,      1,      0,      inf,    inf,    inf},
            {1,     inf,    inf,    inf,    0,      inf,    1},
            {1,     1,      inf,    inf,    inf,    0,      9},
            {inf,   inf,    inf,    inf,    1,      9,      0}
    };
    std::vector<std::vector<int>> Path(matrix.size(), std::vector(matrix.size(), -1));
    alg(matrix, Path);

    for (int i = 0; i < Path.size(); ++i) {
        for (int j = 0; j < Path.size(); ++j) {
            std::cout<<Path[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }

    size_t numVertexes = matrix.size();

    std::vector<sf::CircleShape> vertexes;
    vertexes.reserve(numVertexes);
    for (int i = 0; i < numVertexes; ++i) {
        vertexes.emplace_back(5);
        vertexes[i].setFillColor(sf::Color::Black);
        vertexes[i].setOrigin(5, 5);
        double angle = 2 * M_PI * i / numVertexes;
        vertexes[i].setPosition(cos(angle) * VERTEX_RADIUS + WIDTH / 2, sin(angle) * VERTEX_RADIUS + HEIGHT / 2);
    }

    double vectorShift = 15;
    double gap = 100;
    std::vector<std::vector<Edge>> edges(numVertexes, std::vector<Edge>(numVertexes, Edge(sf::Vector2f(0,0),sf::Vector2f(0,0), sf::Color::Black)));

    for (int i = 0; i < numVertexes; ++i) {
        for (int j = 0; j < numVertexes; ++j) {
            if (matrix[i][j] != 0 and matrix[i][j] != inf) {
                sf::Vector2f begin = vertexes[i].getPosition();
                sf::Vector2f end = vertexes[j].getPosition();
                sf::Vector2f vec = begin - end;
                double vecLen = sqrt(vec.x * vec.x + vec.y * vec.y);
                sf::Vector2f shiftVec = sf::Vector2f(vectorShift * vec.y / vecLen, vectorShift * -vec.x / vecLen);
                sf::Vector2f gapVec = sf::Vector2f(gap * vec.x / vecLen, gap * vec.y / vecLen);
                begin += shiftVec - gapVec;
                end += shiftVec + gapVec;
                edges[i][j] = Edge(begin, end, sf::Color::Black);
            }
        }
    }

    bool animated = false;
    int from, to;
    sf::Clock clock;
    float time = 0;
    int vertexCounter = 0;
    int vertexCount = 0;
    std::vector<int> path;

    while (window.isOpen()) {
        if(vertexCounter == vertexCount){
            animated = false;
        }

        if(animated){
            time = clock.getElapsedTime().asMilliseconds();
            if((int)(time/2000) > vertexCounter) {
                vertexCounter++;
            }
            if(vertexCounter < vertexCount){
                edges[path[vertexCounter]][path[vertexCounter+1]].Colour = sf::Color::Yellow;
            }
        }


        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        for (const auto &vertex: vertexes) {
            window.draw(vertex);
        }
        for (int i = 0; i < numVertexes; ++i) {
            for (int j = 0; j < numVertexes; ++j) {
                if(edges[i][j].Point2 != sf::Vector2f(0,0)){
                    window.draw(edges[i][j]);
                }
            }
        }

        window.display();

        if(animated and vertexCounter < vertexCount){
            edges[path[vertexCounter]][path[vertexCounter+1]].Colour = sf::Color::Black;
        }


        if(!animated){
            std::cin>>from>>to;
            clock.restart();
            path = getPath(Path, from, to);
            for(auto& p: path){
                std::cout<<p;
            }
            std::cout<<std::endl;
            vertexCounter = 0;
            vertexCount = path.size() - 1;
            animated = true;
        }
    }



    return 0;
}
