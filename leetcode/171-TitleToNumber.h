/************************************************************************************************************************
����һ��Excel�����е������ƣ���������Ӧ������š�

���磬

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
ʾ�� 1:

����: "A"
���: 1
ʾ�� 2:

����: "AB"
���: 28
ʾ�� 3:

����: "ZY"
���: 701
************************************************************************************************************************/
//mn=m*26+n
#include<string>
using namespace std;
class TitleToNumber {
public:
	//A:ascii-64
	int titleToNumber(string s) {
		int res = 0;
		int n = s.length() - 1;
		for (int i = 0; i < s.length(); ++i) {
			res += (s[i] - 64) * pow(26, n);
			n -= 1;
		}
		return res;
	}
};