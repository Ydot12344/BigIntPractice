//
// Created by ydot on 23.09.2021.
//

#include"gtest/gtest.h"
#include "../BigInt.h"

TEST(TestBigInt, test1){
    BigInt a = BigInt("1000");
    BigInt b = BigInt(12);
    EXPECT_EQ(a + b , BigInt(1012));
    EXPECT_EQ(a - b , BigInt(988));
    EXPECT_EQ(a / b, BigInt(83));
    EXPECT_EQ(a % b, BigInt(4));
    EXPECT_GT(a, b);
    EXPECT_GE(a, b);
    EXPECT_NE(a, b);
    EXPECT_LT(b, a);
    EXPECT_LE(b, a);
}

TEST(TestBigInt, test2){
    BigInt a = BigInt("-1000");
    BigInt b = BigInt(12);
    ASSERT_EQ(a + b , BigInt("-988"));
    ASSERT_EQ(a - b , BigInt("-1012"));
    EXPECT_EQ(a / b, BigInt(-83));
    EXPECT_EQ(a % b, BigInt(-4));
    EXPECT_GT(b, a);
    EXPECT_GE(b, a);
    EXPECT_NE(a, b);
    EXPECT_LT(a, b);
    EXPECT_LE(a, b);
}


TEST(TestBigInt, test3){
    BigInt a = BigInt("-1000");
    BigInt b = BigInt("-12");
    ASSERT_EQ(a + b , BigInt("-1012"));
    ASSERT_EQ(a - b , BigInt("-988"));
    EXPECT_EQ(a / b, BigInt(83));
    EXPECT_EQ(a % b, BigInt(-4));
    EXPECT_GT(b, a);
    EXPECT_GE(b, a);
    EXPECT_NE(a, b);
    EXPECT_LT(a, b);
    EXPECT_LE(a, b);
}


TEST(TestBigInt, test4){
    BigInt a = BigInt("-12");
    BigInt b = BigInt("1000");
    ASSERT_EQ(a + b , BigInt("988"));
    ASSERT_EQ(a - b , BigInt("-1012"));
    EXPECT_EQ(a / b, BigInt(-12 / 1000));
    EXPECT_EQ(a % b, BigInt(-12 % 1000));
    EXPECT_GT(b, a);
    EXPECT_GE(b, a);
    EXPECT_NE(a, b);
    EXPECT_LT(a, b);
    EXPECT_LE(a, b);
}

TEST(TestBigInt, test5){
    BigInt a = BigInt("12");
    BigInt b = BigInt("-1000");
    EXPECT_EQ(a / b, BigInt(12 / -1000));
    EXPECT_EQ(a % b, BigInt(12 % -1000));
    ASSERT_EQ(a + b , BigInt("-988"));
    ASSERT_EQ(a - b , BigInt("1012"));
    EXPECT_GT(a, b);
    EXPECT_GE(a, b);
    EXPECT_NE(a, b);
    EXPECT_LT(b, a);
    EXPECT_LE(b, a);
}
TEST(TestBigInt, test6){
    BigInt a = BigInt("-12");
    BigInt b = BigInt("-1000");
    EXPECT_EQ(a / b, BigInt(-12 / -1000));
    EXPECT_EQ(a % b, BigInt(-12 % -1000));
    ASSERT_EQ(a + b , BigInt("-1012"));
    ASSERT_EQ(a - b , BigInt("988"));
    EXPECT_GT(a, b);
    EXPECT_GE(a, b);
    EXPECT_NE(a, b);
    EXPECT_LT(b, a);
    EXPECT_LE(b, a);
}

TEST(TestBigInt, test7){
    BigInt a = BigInt("12301239123087128379128398127398");
    BigInt b = BigInt("12301239123087128379128398127398");
    EXPECT_EQ(a / b, BigInt(1));
    EXPECT_EQ(a % b, BigInt(0));
    EXPECT_EQ(a, b);
}

TEST(TestBigInt, devide_by_zero){
    BigInt a = 12;
    BigInt b = 0;
    EXPECT_THROW(a / b, BigInt::divided_by_zero);
}

