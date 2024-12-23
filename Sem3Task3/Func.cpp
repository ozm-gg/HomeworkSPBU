#include <stdexcept>
#include "Func.h"

std::vector<int> TwoToOne(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        throw std::invalid_argument("Input matrix is empty");
    }

    int num_rows = matrix.size();
    int num_cols = matrix[0].size();

    std::vector<int> result(num_rows * num_cols);

    auto res_iter = result.begin();
    for (auto i = matrix.begin(); i != matrix.end(); ++i) {
        for (auto j = (*i).begin(); j != (*i).end(); ++j) {
            *(res_iter + (i - matrix.begin()) * num_cols + ( j - (*i).begin())) = *j;
        }
    }

    return result;
}

std::vector<std::vector<int>> OneToTwo(std::vector<int>& vec, int num_cols) {
    if (vec.empty()) {
        throw std::invalid_argument("Input vector is empty");
    }

    if (vec.size() % num_cols != 0) {
        throw std::invalid_argument("Input vector size is not divisible by number of columns");
    }

    int num_rows = vec.size() / num_cols;
    std::vector<std::vector<int>> result(num_rows);
    for(auto& row : result){
        row = std::vector<int>(num_cols);
    }

    for (auto vec_iter =  vec.begin(); vec_iter != vec.end(); ++vec_iter) {

        int i = ((vec_iter - vec.begin()) - (vec_iter - vec.begin()) % num_cols) / num_cols;
        int j = (vec_iter - vec.begin()) - i * num_cols;
        auto res_iter = (*(result.begin() + i)).begin() + j;
        *res_iter = *vec_iter;
    }

    return result;
}

void SortByColumnSums(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        throw std::invalid_argument("Input matrix is empty");
    }

    size_t nCols = matrix[0].size();
    size_t nRows = matrix.size();

    std::vector<int> columnSums(nCols, 0);
    for (const auto& row : matrix) {
        for (size_t j = 0; j < nCols; ++j) {
            columnSums[j] += row[j];
        }
    }

    std::vector<size_t> indices(nCols);
    for (size_t i = 0; i < nCols; ++i) {
        indices[i] = i;
    }

    std::sort(indices.begin(), indices.end(), [&](size_t a, size_t b) {
        return columnSums[a] < columnSums[b];
    });

    std::vector<std::vector<int>> sortedMatrix(nRows, std::vector<int>(nCols));
    for (size_t i = 0; i < nCols; ++i) {
        for (size_t j = 0; j < nRows; ++j) {
            sortedMatrix[j][i] = matrix[j][indices[i]];
        }
    }

    matrix = std::move(sortedMatrix);
}