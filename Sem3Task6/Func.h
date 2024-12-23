#include <vector>
#include <set>

#ifndef SEM3TASK6_FUNC_H
#define SEM3TASK6_FUNC_H

struct Point {
    int x;
    int y;

    int distanceSquared() const {
        return x * x + y * y;
    }
};

bool comparePoints(const Point &a, const Point &b);

void RadAngSort(std::vector<Point>& points);

std::pair<int, std::set<int>> SubTask2(std::vector<int> vec);

std::vector<std::pair<int, int>> maximizeNumber(std::vector<double>& nums);

#endif //SEM3TASK6_FUNC_H
