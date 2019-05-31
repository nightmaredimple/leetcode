#include "gtest\gtest.h"
#include "TwoSum.h"
#include "AddTwoNumbers.h"
#include "LongestSubstringWithoutRepeatingCharacters.h"
#include "FindMedianSortedArrays.h"

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

TEST(AddTwoNumbers, case2)
{
	AddTwoNumbers s;
	vector<int> input1 = { 2, 4, 3 };
	vector<int> input2 = { 5, 6, 4 };
	vector<int> output = { 7, 0, 8 };
	ListNode* x1 = createList(input1);
	ListNode* x2 = createList(input2);
	ListNode* y = createList(output);

	EXPECT_EQ(true, compareList(y,s.addTwoNumbers(x1, x2)));
}

TEST(LongestSubstringWithoutRepeatingCharacters, case3)
{
	LongestSubstringWithoutRepeatingCharacters s;
	string c = "pwwkew";
	EXPECT_EQ(3, s.lengthOfLongestSubstring1(c));
	EXPECT_EQ(3, s.lengthOfLongestSubstring2(c));
}

TEST(FindMedianSortedArrays, case4)
{
	FindMedianSortedArrays s;
	vector<int> nums1 = { 1, 3 };
	vector<int> nums2 = { 2 };
	double res1 = 2.0;
	EXPECT_EQ(res1, s.findMedianSortedArrays1(nums1, nums2));
	EXPECT_EQ(res1, s.findMedianSortedArrays2(nums1, nums2));

	vector<int> nums3 = { 1, 3 };
	vector<int> nums4 = { };
	double res2 = 2.0;
	EXPECT_EQ(res2, s.findMedianSortedArrays1(nums3, nums4));
	EXPECT_EQ(res2, s.findMedianSortedArrays2(nums3, nums4));
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc,argv);
	if (RUN_ALL_TESTS()) 
		return 0;
}