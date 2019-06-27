/************************************************************************************************************************
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:

输入: "III"
输出: 3
示例 2:

输入: "IV"
输出: 4
示例 3:

输入: "IX"
输出: 9
示例 4:

输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
示例 5:

输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
************************************************************************************************************************/
#include<string>
#include<unordered_map>
using namespace std;

class RomanToInt {
public:
	//仅需要考虑4,9这类特殊情况，其他的只需要相加
	//采用数组的方式存储字典会更快更省内存
	//最好还是初始化以下m，或者像我一样单独取出i=len-1的情况，因为string最后一位是NULL，对应m[0]，不初始化的话是随机数
	int romanToInt1(string s) {
		/*
		unordered_map<char, int> m;
		m.insert(make_pair('I', 1));
		m.insert(make_pair('V', 5));
		m.insert(make_pair('X', 10));
		m.insert(make_pair('L', 50));
		m.insert(make_pair('C', 100));
		m.insert(make_pair('D', 500));
		m.insert(make_pair('M', 1000));
		*/
		int m[100];
		m['I'] = 1;
		m['V'] = 5;
		m['X'] = 10;
		m['L'] = 50;
		m['C'] = 100;
		m['D'] = 500;
		m['M'] = 1000;
		int res = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (i == s.length() - 1 || m[s[i]] >= m[s[i + 1]]) {
				res += m[s[i]];
			}
			else {
				res += m[s[i + 1]] - m[s[i]];
				i++;
			}
		}
		return res;

	}

	//纯属刷榜行为，因为A对应ascii码65
	int romanToInt2(string s) {
		int m[26];
		m['I' - 65] = 1;
		m['V' - 65] = 5;
		m['X' - 65] = 10;
		m['L' - 65] = 50;
		m['C' - 65] = 100;
		m['D' - 65] = 500;
		m['M' - 65] = 1000;
		int res = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (i == s.length() - 1 || m[s[i] - 65] >= m[s[i + 1] - 65]) {
				res += m[s[i] - 65];
			}
			else {
				res += m[s[i + 1] - 65] - m[s[i] - 65];
				i++;
			}
		}
		return res;

	}
};