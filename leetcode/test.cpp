#include "gtest\gtest.h"

int fun(int a, int b)
{
	return (a - b);
}

TEST(fun, case1)
{
	EXPECT_LT(-2, fun(1, 2));
	EXPECT_EQ(-1, fun(1, 2));
	ASSERT_LT(-2, fun(1, 2));
	ASSERT_EQ(-1, fun(1, 2));
}
int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}