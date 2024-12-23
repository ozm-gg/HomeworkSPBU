#include "Func.h"
#include <vector>
#include <algorithm>

bool BinSearch(const std::vector<int> &vec, int value) {
    return std::binary_search(vec.begin(), vec.end(), value);
}
