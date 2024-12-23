#include <gtest/gtest.h>
#include "Func.h"

TEST(BinSearchTest, BinSearch) {
    EXPECT_TRUE(BinSearch(std::vector<int>({1,2,3,4,5,6,7}), 1));
    EXPECT_FALSE(BinSearch(std::vector<int>({2,3,4,5,6,7,8}), 1));
}

TEST(SuiteName, TestName) {
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}