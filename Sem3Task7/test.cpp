#include <gtest/gtest.h>
#include "Func.h"

TEST(ProfessorsGameTest, BasicTest) {
    std::vector<int> input = {1, 2, 3, 4};
    int k = 1;
    std::vector<int> expected = {2, 3, 4, 5};
    EXPECT_EQ(ProfessorsGame(input, k), expected);
}

TEST(ProfessorsGameTest, MultipleOperationsTest) {
    std::vector<int> input = {4, 3, 2, 1};
    int k = 2;
    std::vector<int> expected = {5, 1073741821, 4, 3};
    EXPECT_EQ(ProfessorsGame(input, k), expected);
}

TEST(ProfessorsGameTest, LargeKTest) {
    std::vector<int> input = {1, 2, 3, 4};
    int k = 1000;
    std::vector<int> expected = {1062488873, 1072033429, 1060433235, 57573251};
    EXPECT_EQ(ProfessorsGame(input, k), expected);
}

TEST(ProfessorsGameTest, AllElementsSameWithOddK) {
    std::vector<int> input = {5, 5, 5, 5};
    int k = 1001;
    std::vector<int> expected = {0, 5, 5, 5};
    EXPECT_EQ(ProfessorsGame(input, k), expected);
}

TEST(ProfessorsGameTest, AllElementsSameWithEvenK) {
    std::vector<int> input = {5, 5, 5, 5};
    int k = 1000;
    std::vector<int> expected = {5, 5, 5, 5};
    EXPECT_EQ(ProfessorsGame(input, k), expected);
}

TEST(ProfessorsGameTest, SingleElement) {
    std::vector<int> input = {42};
    int k = 100;
    std::vector<int> expected = {0};
    EXPECT_EQ(ProfessorsGame(input, k), expected);
}

TEST(ProfessorsGameTest, MaxValueTest) {
    std::vector<int> input = {1, 1073741823};
    int k = 1;
    std::vector<int> expected = {1073741823, 0};
    EXPECT_EQ(ProfessorsGame(input, k), expected);
}

TEST(ProfessorsDictionaryTest, BasicTest) {
    std::vector<std::string> input = {
            "apple - malum, pomum, popula",
            "fruit - baca, bacca, popum",
            "punishment - malum, multa"
    };

    auto result = VasyasDictionary(3, input);

    ASSERT_EQ(result.size(), 7);


    EXPECT_EQ(result[0].first, "baca");
    EXPECT_EQ(result[0].second, std::vector<std::string>({"fruit"}));

    EXPECT_EQ(result[1].first, "bacca");
    EXPECT_EQ(result[1].second, std::vector<std::string>({"fruit"}));

    EXPECT_EQ(result[2].first, "malum");
    EXPECT_EQ(result[2].second, std::vector<std::string>({"apple", "punishment"}));

    EXPECT_EQ(result[3].first, "multa");
    EXPECT_EQ(result[3].second, std::vector<std::string>({"punishment"}));

    EXPECT_EQ(result[4].first, "pomum");
    EXPECT_EQ(result[4].second, std::vector<std::string>({"apple"}));

    EXPECT_EQ(result[5].first, "popula");
    EXPECT_EQ(result[5].second, std::vector<std::string>({"apple"}));

    EXPECT_EQ(result[6].first, "popum");
    EXPECT_EQ(result[6].second, std::vector<std::string>({"fruit"}));
}



TEST(MarkQueueTest, Test1) {
    std::string input = "3\n"
                        "2 of sweets\n"
                        "5 of milk\n"
                        "1 of sausage\n"
                        "4\n"
                        "6 of milk\n"
                        "3 of milk\n"
                        "1 of milk\n"
                        "3 of sweets\n";

    double result = calculateTime(input);
    EXPECT_DOUBLE_EQ(result, 8);
}
TEST(MarkQueueTest, Test2) {
    std::string input = "3\n"
                        "2 of sweets\n"
                        "4 of milk\n"
                        "1 of sausage\n"
                        "4\n"
                        "2 of milk\n"
                        "3 of sweets\n"
                        "3 of milk\n"
                        "1 of cheese\n";

    double result = calculateTime(input);
    EXPECT_DOUBLE_EQ(result, 6);
}

TEST(MarkQueueTest, Test3) {
    std::string input = "1\n"
                        "3 of a\n"
                        "3\n"
                        "4 of a\n"
                        "1 of a\n"
                        "1 of b\n";

    double result = calculateTime(input);
    EXPECT_DOUBLE_EQ(result, 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}