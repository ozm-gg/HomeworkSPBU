#include <gtest/gtest.h>
#include "Func.h"

class ClearSpacesTest : public ::testing::Test {
};

TEST_F(ClearSpacesTest, StringWithExtraSpaces) {
    std::string str = "   Это   тестовая   строка   с   пробелами   ";
    std::string result = ClearSpaces(str);
    EXPECT_EQ(result, "Это тестовая строка с пробелами");
}

TEST_F(ClearSpacesTest, StringWithoutSpaces) {
    std::string str = "Безпробелов";
    std::string result = ClearSpaces(str);
    EXPECT_EQ(result, "Безпробелов");
}

TEST_F(ClearSpacesTest, OnlySpaces) {
    std::string str = "     ";
    std::string result = ClearSpaces(str);
    EXPECT_EQ(result, "");
}

TEST_F(ClearSpacesTest, EmptyString) {
    std::string str = "";
    std::string result = ClearSpaces(str);
    EXPECT_EQ(result, "");
}

TEST_F(ClearSpacesTest, SingleWordWithSpaces) {
    std::string str = "   слово   ";
    std::string result = ClearSpaces(str);
    EXPECT_EQ(result, "слово");
}

TEST_F(ClearSpacesTest, SpacesAtStartAndEnd) {
    std::string str = "   Пример строки   ";
    std::string result = ClearSpaces(str);
    EXPECT_EQ(result, "Пример строки");
}

class MakeStringWithNoLastWordTest : public ::testing::Test {
};

TEST_F(MakeStringWithNoLastWordTest, DifferentWords) {
    std::string str = "Это тестовая строка с разными словами";
    std::string expected_output = "Это тестовая строка с разными";
    EXPECT_EQ(MakeStringWithNoLastWord(str), expected_output);
}

TEST_F(MakeStringWithNoLastWordTest, RepeatedLastWord) {
    std::string str = "пример строки с повторяющимся словом пример";
    std::string expected_output = "строки с повторяющимся словом";
    EXPECT_EQ(MakeStringWithNoLastWord(str), expected_output);
}

TEST_F(MakeStringWithNoLastWordTest, SingleWord) {
    std::string str = "однослово";
    std::string expected_output = ""; 
    EXPECT_EQ(MakeStringWithNoLastWord(str), expected_output);
}

TEST_F(MakeStringWithNoLastWordTest, AllSameWords) {
    std::string str = "слово слово слово слово";
    std::string expected_output = "";
    EXPECT_EQ(MakeStringWithNoLastWord(str), expected_output);
}

TEST_F(MakeStringWithNoLastWordTest, EmptyString) {
    std::string str = "";
    std::string expected_output = "";
    EXPECT_EQ(MakeStringWithNoLastWord(str), expected_output);
}

class DropWordsWithNoUniqueCharsTest : public ::testing::Test {
};

TEST_F(DropWordsWithNoUniqueCharsTest, MixedWords) {
    std::string str = "hello world abc defg";
    std::string result = DropWordsWithNoUniqueChars(str);
    EXPECT_EQ(result, "world abc defg");
}

TEST_F(DropWordsWithNoUniqueCharsTest, AllWordsWithDuplicates) {
    std::string str = "hello moon noon";
    std::string result = DropWordsWithNoUniqueChars(str);
    EXPECT_EQ(result, "");
}

TEST_F(DropWordsWithNoUniqueCharsTest, AllWordsUnique) {
    std::string str = "abc defg hij";
    std::string result = DropWordsWithNoUniqueChars(str);
    EXPECT_EQ(result, "abc defg hij");
}

TEST_F(DropWordsWithNoUniqueCharsTest, EmptyString) {
    std::string str = "";
    std::string result = DropWordsWithNoUniqueChars(str);
    EXPECT_EQ(result, "");
}

TEST_F(DropWordsWithNoUniqueCharsTest, SingleWordWithDuplicates) {
    std::string str = "noon";
    std::string result = DropWordsWithNoUniqueChars(str);
    EXPECT_EQ(result, "");
}

TEST_F(DropWordsWithNoUniqueCharsTest, SingleWordUnique) {
    std::string str = "abcd";
    std::string result = DropWordsWithNoUniqueChars(str);
    EXPECT_EQ(result, "abcd");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}