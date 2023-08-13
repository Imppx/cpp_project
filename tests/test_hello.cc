#include "hello/hello.h"
#include "gtest/gtest.h"


TEST(HelloTest, VerifyRetVal) {
    ASSERT_EQ(Hello(), 0) << "Output is not 0" << std::endl;
}

TEST(SumTest, HandleNegativeInput) {
    ASSERT_EQ(Sum(-2, -5), -7);
}

TEST(SumTest, HandleZeroInput) {
    ASSERT_EQ(Sum(0, -5), -5);
    ASSERT_EQ(Sum(0, 12), 12);
    ASSERT_EQ(Sum(0, 0), 0);
}

TEST(SumTest, HandlePositiveInput) {
    ASSERT_EQ(Sum(5, 5), 10);
    ASSERT_EQ(Sum(100, 23), 123);
}