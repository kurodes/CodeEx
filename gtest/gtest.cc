#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
#include <assert.h>
#include <math.h>

using namespace std;

double square_root(const double x)
{
    if (x < 0) return -1;
    double sr = sqrt(x);
    return sr;
}

TEST(square_root_test, positive_nums)
{
    EXPECT_EQ(2.0, square_root(4.0));
    // EXPECT_EQ(1.73205, square_root(3.0));
}

TEST(square_root_test, zero_negetive_nums)
{
    EXPECT_EQ(0.0, square_root(0.0));
    ASSERT_EQ(-1, square_root(-2.0));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    string A = "fasdfaf";
    int tmp;
    tmp = RUN_ALL_TESTS();
    assert(1.0 == square_root(4.0));
    return 0;
}