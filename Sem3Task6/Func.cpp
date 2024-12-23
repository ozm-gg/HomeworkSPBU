#include <algorithm>
#include <queue>
#include "Func.h"

bool comparePoints(const Point &a, const Point &b) {
    int distA = a.distanceSquared();
    int distB = b.distanceSquared();

    if (distA != distB) {
        return distA < distB;
    }

    if (a.x == 0 && a.y > 0) {
        return true;
    }

    if (b.x == 0 && b.y > 0) {
        return false;
    }

    if (a.x >= 0 && b.x <= 0) {
        return false;
    }

    if (a.x <= 0 && b.x >= 0) {
        return true;
    }

    return (a.x * b.y > b.x * a.y);
}

void RadAngSort(std::vector<Point>& points) {
    std::sort(points.begin(), points.end(), comparePoints);
}

std::pair<int, std::set<int>> SubTask2(std::vector<int> vec) {
    int N = vec.size();
    std::set<int> res(vec.begin(), vec.end());
    return std::pair(N-res.size(), res);
}

std::vector<std::pair<int, int>> maximizeNumber(std::vector<double>& nums) {
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> minHeap;

    for (int i = 0; i < nums.size(); ++i){
        minHeap.emplace(nums[i],i+1);
    }

    std::vector<std::pair<int, int>> res;

    int nextIndex = minHeap.size() + 1;
    while (minHeap.size() > 1) {
        auto first = minHeap.top(); minHeap.pop();
        auto second = minHeap.top(); minHeap.pop();

        if(first.second > second.second) res.emplace_back(second.second, first.second);
        else res.emplace_back(first.second, second.second);

        double average = (first.first + second.first) / 2.0;
        minHeap.emplace(average,  nextIndex);
        nextIndex++;
    }

    return res;
}