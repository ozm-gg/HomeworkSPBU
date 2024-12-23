#include <gtest/gtest.h>
#include "Func.h"

TEST(OneToTwoTests, SimpleCase) {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    auto result = OneToTwo(vec, 2);
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result, std::vector<std::vector<int>>({{1, 2},
                                                     {3, 4},
                                                     {5, 6}}));

}

TEST(OneToTwoTests, EmptyVector) {
    std::vector<int> vec = {};
    EXPECT_THROW(OneToTwo(vec, 2), std::invalid_argument);
}

TEST(OneToTwoTests, SizeNotDivisible) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_THROW(OneToTwo(vec, 2), std::invalid_argument);
}

TEST(TwoToOneTests, SimpleCase) {
    std::vector<std::vector<int>> vec = {{1, 2},
                                         {3, 4},
                                         {5, 6}};
    auto result = TwoToOne(vec);
    ASSERT_EQ(result.size(), 6);
    EXPECT_EQ(result, std::vector<int>({1, 2, 3, 4, 5, 6}));
}

TEST(TwoToOneTests, EmptyMatrix) {
    std::vector<std::vector<int>> vec = {};
    EXPECT_THROW(TwoToOne(vec), std::invalid_argument);
}

TEST(TwoToOneTests, EmptyRow) {
    std::vector<std::vector<int>> vec = {{}};
    auto result = TwoToOne(vec);
    ASSERT_EQ(result.size(), 0);
    EXPECT_EQ(result, std::vector<int>(0));
}

TEST(SortByColumnSumsTests, SimpleCase) {
    std::vector<std::vector<int>> matrix = {
            {3, 2, 1},
            {6, 5, 4},
            {9, 8, 7}
    };

    SortByColumnSums(matrix);

    std::vector<std::vector<int>> expected = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    ASSERT_EQ(matrix, expected);
}

TEST(SortByColumnSumsTests, EmptyMatrix) {
    std::vector<std::vector<int>> matrix = {};
    EXPECT_THROW(SortByColumnSums(matrix), std::invalid_argument);
}

TEST(SortByColumnSumsTests, SingleColumn) {
    std::vector<std::vector<int>> matrix = {
            {1},
            {2},
            {3}
    };

    SortByColumnSums(matrix);

    std::vector<std::vector<int>> expected = {
            {1},
            {2},
            {3}
    };

    ASSERT_EQ(matrix, expected);
}

TEST(SortByColumnSumsTests, NegativeValues) {
    std::vector<std::vector<int>> matrix = {
            {-1, -2, -3},
            {-4, -5, -6},
            {-7, -8, -9}
    };

    SortByColumnSums(matrix);

    std::vector<std::vector<int>> expected = {
            {-3, -2, -1},
            {-6, -5, -4},
            {-9, -8, -7}
    };

    ASSERT_EQ(matrix, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}