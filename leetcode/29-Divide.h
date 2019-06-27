/************************************************************************************************************************
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
说明:

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [?2^31,  2^31 ? 1]。本题中，如果除法结果溢出，则返回 2^31 ? 1。
************************************************************************************************************************/
#include<algorithm>
using namespace std;
class Divide {
public:
	int divide(int dividend, int divisor) {
		long long y = abs((long long)dividend);
		long long x = abs((long long)divisor);

		long long scale = 1, res = 0;
		while (y >= (x << 1)) {
			x <<= 1;
			scale <<= 1;
		}

		while (scale > 0) {
			if (y >= x) {
				y -= x;
				res += scale;
			}
			x >>= 1;
			scale >>= 1;
		}
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
			res = -res;
		res = min(max(double(res), double(INT_MIN)), double(INT_MAX));
		return int(res);
	}
};