#include "gtest\gtest.h"
#include "1-TwoSum.h"
#include "2-AddTwoNumbers.h"
#include "3-LongestSubstringWithoutRepeatingCharacters.h"
#include "4-FindMedianSortedArrays.h"
#include "7-Reverse.h"
#include "8-MyAtoi.h"
#include "13-RomanToInt.h"
#include "29-Divide.h"
#include "50-MyPow.h"
#include "69-MySqrt.h"
#include "166-FractionToDecimal.h"
#include "171-TitleToNumber.h"
#include "172-TrailingZeroes.h"
#include "202-IsHappy.h"
#include "204-CountPrimes.h"
#include "268-MissingNumber.h"
#include "279-NumSquares.h"
#include "326-IsPowerOfThree.h"



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

TEST(Reverse, case5)
{
	Reverse s;

	EXPECT_EQ(21, s.reverse(120));
	EXPECT_EQ(0, s.reverse(-2147483648));

}

TEST(MyAtoi, case14)
{
	MyAtoi s;

	EXPECT_EQ(-2147483648, s.myAtoi("-91283472332"));
	EXPECT_EQ(0, s.myAtoi("words and 987"));
	EXPECT_EQ(-42, s.myAtoi("   -42"));
}

TEST(RomanToInt, case6)
{
	RomanToInt s;

	EXPECT_EQ(58, s.romanToInt1("LVIII"));
	EXPECT_EQ(58, s.romanToInt2("LVIII"));

}

TEST(Divide, case15)
{
	Divide s;

	EXPECT_EQ(-2, s.divide(7, -3));

}

TEST(MyPow, case16)
{
	MyPow s;

	EXPECT_EQ(0.25, s.myPow1(2.00000, -2));
	EXPECT_EQ(0.25, s.myPow2(2.00000, -2));
	EXPECT_EQ(0.25, s.myPow3(2.00000, -2));
	EXPECT_EQ(0.25, s.myPow4(2.00000, -2));
}

TEST(MySqrt, case7)
{
	MySqrt s;

	EXPECT_EQ(2, s.mySqrt1(8));
	EXPECT_EQ(2, s.mySqrt2(8));
	EXPECT_EQ(2, s.mySqrt3(8));

	EXPECT_EQ(46340, s.mySqrt1(2147483647));
	EXPECT_EQ(46340, s.mySqrt2(2147483647));
	EXPECT_EQ(46340, s.mySqrt3(2147483647));


}

TEST(FractionToDecimal, case17)
{
	FractionToDecimal s;

	EXPECT_EQ("0.(6)", s.fractionToDecimal1(2, 3));
	EXPECT_EQ("0.(6)", s.fractionToDecimal2(2, 3));
}

TEST(TitleToNumber, case8)
{
	TitleToNumber s;

	EXPECT_EQ(701, s.titleToNumber("ZY"));

}

TEST(TrailingZeroes, case9)
{
	TrailingZeroes s;

	EXPECT_EQ(7, s.trailingZeroes(30));

}

TEST(IsHappy, case10)
{
	IsHappy s;

	EXPECT_EQ(true, s.isHappy(19));
	EXPECT_EQ(false, s.isHappy(89));

}

TEST(CountPrimes, case11)
{
	CountPrimes s;

	EXPECT_EQ(4, s.countPrimes1(10));
	EXPECT_EQ(4, s.countPrimes2(10));
}

TEST(MissingNumber, case12)
{
	MissingNumber s;
	vector<int> m = { 9,6,4,2,3,5,7,0,1 };

	EXPECT_EQ(8, s.missingNumber(m));

}

TEST(NumSquares, case18)
{
	NumSquares s;

	EXPECT_EQ(2, s.numSquares(13));

}

TEST(IsPowerOfThree, case13)
{
	IsPowerOfThree s;

	EXPECT_EQ(false, s.isPowerOfThree1(45));
	EXPECT_EQ(true, s.isPowerOfThree1(27));

	EXPECT_EQ(false, s.isPowerOfThree2(45));
	EXPECT_EQ(true, s.isPowerOfThree2(27));

	EXPECT_EQ(false, s.isPowerOfThree3(45));
	EXPECT_EQ(true, s.isPowerOfThree3(27));

	EXPECT_EQ(false, s.isPowerOfThree4(45));
	EXPECT_EQ(true, s.isPowerOfThree4(27));
}









//int main(int argc, char **argv) {
//	testing::InitGoogleTest(&argc,argv);
//	if (RUN_ALL_TESTS()) 
//		return 0;
//}