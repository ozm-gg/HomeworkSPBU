#include <gtest/gtest.h>
#include "Func.h"

TEST(ComparePointsTest, PosSigns){
    Point point1 = {-3, 4};
    Point point2 = {-3,  -4};
    EXPECT_TRUE(comparePoints(point1, point2));
}

TEST(ComparePointsTest, NegSigns){
    Point point1 = {3, 4};
    Point point2 = {3, -4};
    EXPECT_TRUE(comparePoints(point2, point1));
}

TEST(ComparePointsTest, DifSigns){
    Point point1 = {3, 4};
    Point point2 = {-3, -4};
    EXPECT_TRUE(comparePoints(point2, point1));
}

TEST(ComparePointsTest, DifDist){
    Point point1 = {3, 4};
    Point point2 = {6, 8};
    EXPECT_TRUE(comparePoints(point1, point2));
}

TEST(ComparePointsTest, FirstPoint){
    Point point = {0, 5};
    Point point1 = {3, 4};
    Point point2 = {-3, 4};
    Point point3 = {-5, 0};
    EXPECT_TRUE(comparePoints(point, point1));
    EXPECT_TRUE(comparePoints(point, point2));
    EXPECT_TRUE(comparePoints(point, point3));
}

TEST(PointSortingTest, BasicSorting) {
    std::vector<Point> points = {
            {3, 4},
            {5, 0},
            {4, 3},
            {-5, 0},
            {-3, 4},
            {-3, -4},
            {0, 5},
            {0, -5},
            {4, -3},
            {1, 1}
    };

    RadAngSort(points);

    std::vector<Point> expected = {
            {1, 1},
            {0, 5},
            {-3, 4},
            {-5, 0},
            {-3, -4},
            {0, -5},
            {4, -3},
            {5, 0},
            {4, 3},
            {3, 4}
    };

    EXPECT_EQ(points.size(), expected.size());
    for (size_t i = 0; i < points.size(); ++i) {
        EXPECT_EQ(points[i].x, expected[i].x);
        EXPECT_EQ(points[i].y, expected[i].y);
    }
}

TEST(SubTask2Test, BasicTest) {
    std::vector<int> input = {4, 3, 2, 1, 3, 1};
    auto result = SubTask2(input);

    std::set<int> expected_set = {1, 2, 3, 4};
    EXPECT_EQ(result.first, 2);
    EXPECT_EQ(result.second, expected_set);
}

TEST(MaximizeNumberTest, BasicTest) {
    std::vector<double> nums = {234.0, 2.0, 5.0, 54.0, 5.0};
    std::vector<std::pair<int, int>> result = maximizeNumber(nums);

    EXPECT_EQ(result.size(), nums.size() - 1);

    EXPECT_EQ(result[0], std::make_pair(2, 3));
    EXPECT_EQ(result[1], std::make_pair(5, 6));
    EXPECT_EQ(result[2], std::make_pair(4, 7));
    EXPECT_EQ(result[3], std::make_pair(1, 8));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}