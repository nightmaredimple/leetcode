/************************************************************************************************************************
�������������������� dividend �ͳ��� divisor�������������Ҫ��ʹ�ó˷��������� mod �������

���ر����� dividend ���Գ��� divisor �õ����̡�

ʾ�� 1:

����: dividend = 10, divisor = 3
���: 3
ʾ�� 2:

����: dividend = 7, divisor = -3
���: -2
˵��:

�������ͳ�����Ϊ 32 λ�з���������
������Ϊ 0��
�������ǵĻ���ֻ�ܴ洢 32 λ�з�������������ֵ��Χ�� [?2^31,  2^31 ? 1]�������У�����������������򷵻� 2^31 ? 1��
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