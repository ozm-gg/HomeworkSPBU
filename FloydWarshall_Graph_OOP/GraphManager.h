#include <vector>
#include <SFML/Graphics.hpp>
#ifndef FLOYDWARSHALL_GRAPH_GRAPHMANAGER_H
#define FLOYDWARSHALL_GRAPH_GRAPHMANAGER_H
#define INF 5000

class GraphManager {
public:
    GraphManager(int width, int height,int vertexRad, const std::vector<std::vector<int>>& matrix);
    ~GraphManager();
    void Draw();
private:
    sf::RenderWindow* window;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> Path;
    int width;
    int height;
    int vertexRad;

    void alg(std::vector<std::vector<int>> mat);
    void createPath(std::vector<int>& p, const std::vector<std::vector<int>>& Path, int i, int j);
    std::vector<int> getPath(const std::vector<std::vector<int>>& Path, int i, int j);
};


#endif //FLOYDWARSHALL_GRAPH_GRAPHMANAGER_H
