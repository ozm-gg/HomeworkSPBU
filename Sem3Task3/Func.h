#include "vector"
#include <algorithm>

#ifndef SEM3TASK3_FUNC_H
#define SEM3TASK3_FUNC_H

std::vector<int> TwoToOne(std::vector<std::vector<int>>& matrix);

std::vector<std::vector<int>> OneToTwo(std::vector<int>& vec, int nCols);

void SortByColumnSums(std::vector<std::vector<int>>& matrix);

#endif //SEM3TASK3_FUNC_H
