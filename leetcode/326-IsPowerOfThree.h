/************************************************************************************************************************
给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:

输入: 27
输出: true
示例 2:

输入: 0
输出: false
示例 3:

输入: 9
输出: true
示例 4:

输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？
************************************************************************************************************************/
//3^m / 3^n = 3^(m-n)
class IsPowerOfThree {
public:
	//循环1
	//对于不是3的倍数的实例效率更高
	bool isPowerOfThree1(int n) {
		if (n == 1)
			return true;
		if (n < 3)
			return false;
		while (n > 1) {
			if (n % 3 == 0)
				n /= 3;
			else
				return false;
		}
		return true;
	}

	//循环2
	//对于n=3m的情况效率更高
	bool isPowerOfThree2(int n) {
		if (n == 1)
			return true;
		if (n < 3)
			return false;
		int m = 1;
		while (m < n) {
			m *= 3;
			if (m == n)
				return true;
		}
		return false;
	}

	//递归
	//空间内存更省
	bool isPowerOfThree3(int n) {
		if (n == 1)
			return true;
		if (n < 3)
			return false;
		if (n % 3 != 0)
			return false;
		else
		 return isPowerOfThree3(n/3);
	}

	//耍赖
	//对于n较大的情形效率才高
	bool isPowerOfThree4(int n) {
		return n > 0 && !(1162261467 % n);
	}

};