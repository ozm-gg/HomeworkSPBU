#include <vector>
#include "GraphManager.h"

#define WIDTH 1500
#define HEIGHT 1000
#define VERTEX_RADIUS 400



int main() {

    std::vector<std::vector<int>> matrix{
            {0,      INF,   22,      8,      1,      1,      INF},
            {INF,   0,      INF,    4,      INF,    1,      INF},
            {22,     INF,    0,      1,      INF,    INF,    INF},
            {8,     4,      1,      0,      INF,    INF,    INF},
            {1,     INF,    INF,    INF,    0,      INF,    1},
            {1,     1,     INF,    INF,    INF,    0,      9},
            {INF,   INF,    INF,    INF,    1,      9,      0}
    };

    GraphManager graph(WIDTH, HEIGHT, VERTEX_RADIUS, matrix);
    graph.Draw();

    return 0;
}
