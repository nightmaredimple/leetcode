#include "gtest\gtest.h"
#include "TwoSum.h"

TEST(TwoSum, case1)
{
	TwoSum s;
	vector<int> nums = { 2, 15, 11, 7 };
	int value = 22;
	vector<int> result = { 1, 3 };

	EXPECT_EQ(result, s.twoSum1(nums, value));
	EXPECT_EQ(result, s.twoSum2(nums, value));
	EXPECT_EQ(result, s.twoSum3(nums, value));

}