//
// Created by dan on 06/06/19.
//

#include <gtest/gtest.h>

#include <Utils.h>


TEST(UtilsTest, IsNearlyZeroTest)
{
    EXPECT_TRUE(utils::isNearlyZero(0.00008, 1e-4));
    EXPECT_FALSE(utils::isNearlyZero(0.0001, 1e-4));
}
