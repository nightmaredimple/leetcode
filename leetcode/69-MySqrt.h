/************************************************************************************************************************
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
由于返回类型是整数，小数部分将被舍去。
************************************************************************************************************************/
#include<math.h>

class MySqrt {
public:
	//皮一下
	int mySqrt1(int x) {
		return int(sqrt(x));
	}

	//二分法，不过经验告诉我们完全平方根一定位于0~(n+1)/2之间，可以减少一次搜索
	//执行加法和乘法操作一定要注意int越界
	int mySqrt2(int x) {
		if (x <= 1)
			return x;

		int lmin = 0, lmax = x / 2;
		while (lmin < lmax) {
			int median = (lmin + lmax + 1) / 2;
			int temp = x / median;
			if (median > temp)
				lmax = median - 1;
			else if (median < temp)
				lmin = median;
			else
				return median;
		}
		return lmax;

	}
	//牛顿迭代法:f(x) = f(x0) + f'(x0)(x - x0) = 0
	//x = x0 - f(x0)/f'(x0)
	//y = x^2 - n
	//x = x0 - (x0*x0 - n)/2x0
	//	= x0/2 + n/2x0
	//  = (x0 + n/x0)/2 ,少一次乘法
	int mySqrt3(int x) {
		if (!x)
			return x;
		double last = 0;
		double now = 1;
		while (last != now) {
			last = now;
			now = (last + x / last) / 2;
		}
		return int(now);
	}
};