/************************************************************************************************************************
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
示例 2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
************************************************************************************************************************/

//最简单的方法就是O(2n)的，一遍记录，一遍查找,所以要线性空间和线性时间
//判断有没有漏的可以利用等差数列求和n(n+1)/2-sum，仅需要线性时间
#include<vector>
using namespace std;
class MissingNumber {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		long long total = n*(n + 1) / 2;
		for (int i = 0; i < n; ++i)
			total -= nums[i];
		return int(total);
	}
};