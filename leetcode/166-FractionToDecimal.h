/************************************************************************************************************************
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

如果小数部分为循环小数，则将循环的部分括在括号内。

示例 1:

输入: numerator = 1, denominator = 2
输出: "0.5"
示例 2:

输入: numerator = 2, denominator = 1
输出: "2"
示例 3:

输入: numerator = 2, denominator = 3
输出: "0.(6)"
************************************************************************************************************************/
#include<string>
#include<unordered_map>
using namespace std;
class FractionToDecimal {
public:
	string fractionToDecimal1(int numerator, int denominator) {
		int y = numerator / denominator;
		int x = numerator % denominator;
		string res = to_string(y);
		if (x == 0)
			return res;
		res += '.';
		while (x > 0) {
			numerator = x * 10;
			y = numerator / denominator;
			int temp = numerator % denominator;
			if (x == temp) {
				res += '(' + to_string(y) + ')';
				break;
			}
			else
				res += to_string(y);
			x = temp;
		}
		return res;
	}

	string fractionToDecimal2(int numerator, int denominator) {
		long long m = abs((long long)(numerator));
		long long n = abs((long long)(denominator));

		long y = m / n;
		long x = m % n;
		string res = to_string(y);
		if (x != 0)
			res += '.';
		int count = 0;
		unordered_map<int, int> record;
		while (x > 0) {
			record.insert(make_pair(x, count));
			m = x * 10;
			y = m / n;
			x = m % n;

			unordered_map<int, int>::iterator it = record.find(x);
			res += to_string(y);
			if (it != record.end()) {
				int offset = count - (it->second) + 1;
				res.insert(res.end() - offset, '(');
				res += ')';
				break;
			}
			count++;

		}
		if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
			res = '-' + res;
		return res;
	}
};