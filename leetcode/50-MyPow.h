/************************************************************************************************************************
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [?2^31, 2^31 ? 1] 。
************************************************************************************************************************/
#include<math.h>
class MyPow {
public:
	//皮一下
	double myPow1(double x, int n) {
		return pow(x, double(n));
	}

	//暴力解法：O(n)
	//n特别大的时候肯定会超时
	double myPow2(double x, int n) {
		if (n == 0)
			return 1.0;
		double res = 1;
		long long m = abs(n);
		for (long long i = 1; i <= m; ++i)
			res *= x;
		res = n < 0 ? 1.0 / res : res;
		return res;
	}

	//递归，但是复杂度没变O(n)
	double myPow3(double x, int n) {
		if (n == 0 || x == 0)
			return 1;
		if (n == 1)
			return x;
		if (n < 0) {
			if (n == INT_MIN) {
				return 1.0 / (x*x) * myPow3(x, INT_MIN + 2);
			}
			x = 1.0 / x;
			n = -n;
		}
		return myPow3(x, n / 2) * myPow3(x, n - n / 2);
	}

	//递归，复杂度O(logn),尽可能保证递归部分函数简短
	double myPow4(double x, int n) {
		if (x == 0)
			return 1;
		double res = hPow(x, n);

		return n < 0 ? 1.0 / res : res;

	}
	double hPow(double x, int n) {
		if (n == 0)
			return 1;
		double res = hPow(x, n / 2);
		return res * res * (n % 2 ? x : 1);
	}
};