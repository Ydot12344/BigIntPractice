//
// Created by ydot on 23.09.2021.
//

#include"gtest/gtest.h"
#include "../BigInt.h"

TEST(TestBigInt, test1){
    BigInt a = BigInt("1000");
    BigInt b = BigInt(12);
    ASSERT_EQ(a + b , BigInt(1012));
    ASSERT_EQ(a - b , BigInt(988));
    ASSERT_TRUE(a > b);
    ASSERT_TRUE(a >= b);
    ASSERT_TRUE(a != b);
    ASSERT_TRUE(b < a);
    ASSERT_TRUE(b <= a);
}

TEST(TestBigInt, test2){
    BigInt a = BigInt("-1000");
    BigInt b = BigInt(12);
    ASSERT_EQ(a + b , BigInt("-988"));
    ASSERT_EQ(a - b , BigInt("-1012"));
    ASSERT_TRUE(a < b);
    ASSERT_TRUE(a <= b);
    ASSERT_TRUE(a != b);
    ASSERT_TRUE(b > a);
    ASSERT_TRUE(b >= a);
}


TEST(TestBigInt, test3){
    BigInt a = BigInt("-1000");
    BigInt b = BigInt("-12");
    ASSERT_EQ(a + b , BigInt("-1012"));
    ASSERT_EQ(a - b , BigInt("-988"));
    ASSERT_TRUE(a < b);
    ASSERT_TRUE(a <= b);
    ASSERT_TRUE(a != b);
    ASSERT_TRUE(b > a);
    ASSERT_TRUE(b >= a);
}


TEST(TestBigInt, test4){
    BigInt a = BigInt("-12");
    BigInt b = BigInt("1000");
    ASSERT_EQ(a + b , BigInt("988"));
    ASSERT_EQ(a - b , BigInt("-1012"));
    ASSERT_TRUE(a < b);
    ASSERT_TRUE(a <= b);
    ASSERT_TRUE(a != b);
    ASSERT_TRUE(b > a);
    ASSERT_TRUE(b >= a);
}

TEST(TestBigInt, test5){
    BigInt a = BigInt("12");
    BigInt b = BigInt("-1000");
    ASSERT_EQ(a + b , BigInt("-988"));
    ASSERT_EQ(a - b , BigInt("1012"));
    ASSERT_TRUE(a > b);
    ASSERT_TRUE(a >= b);
    ASSERT_TRUE(a != b);
    ASSERT_TRUE(b < a);
    ASSERT_TRUE(b <= a);
}
TEST(TestBigInt, test6){
    BigInt a = BigInt("-12");
    BigInt b = BigInt("-1000");
    ASSERT_EQ(a + b , BigInt("-1012"));
    ASSERT_EQ(a - b , BigInt("988"));
    ASSERT_TRUE(a > b);
    ASSERT_TRUE(a >= b);
    ASSERT_TRUE(a != b);
    ASSERT_TRUE(b < a);
    ASSERT_TRUE(b <= a);
}

TEST(TestBigInt, test7){
    BigInt a = BigInt("12301239123087128379128398127398");
    BigInt b = BigInt("12301239123087128379128398127398");
    ASSERT_TRUE(a == b);
}

