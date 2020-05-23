#include <gtest/gtest.h>
#include "component.h"
using namespace std;

TEST(SQUARE_ROOT, zero_negtive)
{
    double a = 0;
    EXPECT_EQ(0, square_root(a));
    double b = -2;
    EXPECT_EQ(-1, square_root(b));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}