#include <iostream>
#include <limits>
#include <gtest/gtest.h>
int devision(const int &a, const int &b) {
    int result;
    if (b != 0) {
        result = a/b;
    } else {
        if (a < 0) {
            result = std::numeric_limits<int>::min();
        } else {
            result = std::numeric_limits<int>::max();
        }
    }
    return result;
}


float devision(const float &a, const float &b) {
    float result;
    if (b != 0) {
        result = a/b;
    } else {
        if (a < 0) {
            result = std::numeric_limits<float>::min();
        } else {
            result = std::numeric_limits<float>::max();
        }
    }
    return result;
}

TEST(DevisionTest, HanldeZeroDivisor) {
    ASSERT_EQ(devision(+100,0),
              std::numeric_limits<signed>::max());
    ASSERT_EQ(devision(-100,0),std::numeric_limits<signed>::min());
    ASSERT_EQ(devision(-100.3f,0.0f),std::numeric_limits<float>::min());
    ASSERT_EQ(devision(+100.3f,0.0f),std::numeric_limits<float>::max());
}

TEST(DevisionTest, HanldeZeroDividend) {
    ASSERT_EQ(devision(+0,0),std::numeric_limits<signed>::max());
    /*ASSERT*/EXPECT_EQ(devision(-0,0),std::numeric_limits<signed>::min());
//    ASSERT_EQ(devision(-0.0f,0.0f),std::numeric_limits<float>::min());
    ASSERT_EQ(devision(+0.0f,0.0f),std::numeric_limits<float>::max());
}

TEST(DevisionTest, Normal) {
    ASSERT_EQ(-0,0);
    ASSERT_EQ(devision(+0,0),std::numeric_limits<signed>::max());
//    /*ASSERT*/EXPECT_EQ(devision(-0,0),std::numeric_limits<signed>::min());
//    ASSERT_EQ(devision(-0.0f,0.0f),std::numeric_limits<float>::min());
    ASSERT_EQ(devision(+0.0f,0.0f),std::numeric_limits<float>::max());
}


int main (int _, char**__) {
    ::testing::InitGoogleTest(&_,__);
    return RUN_ALL_TESTS();
}
















