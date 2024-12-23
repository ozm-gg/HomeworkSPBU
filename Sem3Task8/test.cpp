#include <gtest/gtest.h>
#include "Polynomial.h"

TEST(PolynomialTest, EqualityOperator) {
    Polynomial p1({1.0, 2.0, 3.0});
    Polynomial p2({1.0, 2.0, 3.0});
    Polynomial p3({1.0, 3.0, 2.0});

    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(PolynomialTest, OutputOperator) {
    Polynomial p1({1.0, 2.0, 3.0, 0.0, 2.0});
    std::ostringstream stream;
    stream << p1;

    EXPECT_EQ(stream.str(), "1 + 2*X + 3*X^2 + 2*X^4");
}


TEST(PolynomialTest, AdditionOperator) {
    Polynomial p1({1.0, 2.0, 3.0});
    Polynomial p2({2.0, 3.0, 4.0});
    Polynomial expected({3.0, 5.0, 7.0});

    EXPECT_TRUE(p1 + p2 == expected);
}


TEST(PolynomialTest, SubtractionOperator) {
    Polynomial p1({3.0, 2.0, 1.0});
    Polynomial p2({1.0, 1.0, 1.0});
    Polynomial expected({2.0, 1.0, 0.0});

    EXPECT_TRUE(p1 - p2 == expected);
}

TEST(PolynomialTest, MultiplicationOperator) {
    Polynomial p1({1.0, 2.0, 3.0});
    Polynomial p2({2.0, 1.0});
    Polynomial expected({2.0, 5.0, 8.0, 3.0});

    EXPECT_EQ(expected, p1 * p2);
}

TEST(PolynomialTest, MultiplicationOperator1) {
    Polynomial p1({-1.0, 1.0});
    Polynomial p2({1.0, 1.0, 1.0});
    Polynomial expected({-1.0, 0.0, 0.0, 1.0});

    EXPECT_EQ(expected, p1 * p2);
}


TEST(PolynomialTest, ScalarMultiplication) {
    Polynomial p1({1.0, 2.0, 3.0});
    Polynomial expected({2.0, 4.0, 6.0});

    EXPECT_TRUE(p1 * 2.0 == expected);
}

TEST(PolynomialTest, MonomialMultiplication) {
    Polynomial p1({1.0, 2.0, 3.0});
    Monomial m(2.0, 1);
    Polynomial expected({0.0 , 2.0, 4.0, 6.0});

    EXPECT_EQ(p1 * m, expected);
}


TEST(MonomialTest, EqualityOperator) {
    Monomial m1(3.0, 2);
    Monomial m2(3.0, 2);
    Monomial m3(2.0, 2);
    Monomial m4(3.0, 3);

    EXPECT_TRUE(m1 == m2);
    EXPECT_FALSE(m1 == m3);
    EXPECT_FALSE(m1 == m4);
}

TEST(MonomialTest, OutputOperator) {
    Monomial m1(3.0, 2);
    std::ostringstream stream;
    stream << m1;

    EXPECT_EQ(stream.str(), "3*X^2");
}


TEST(MonomialTest, MultiplicationOperator) {
    Monomial m1(3.0, 2);
    Monomial m2(2.0, 1);
    Monomial expected(6.0, 3);

    EXPECT_EQ(m1 * m2, expected);
}


TEST(MonomialTest, ScalarMultiplicationOperator) {
    Monomial m1(3.0, 2);
    Monomial expected(6.0, 2);

    EXPECT_EQ(m1 * 2.0, expected);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}