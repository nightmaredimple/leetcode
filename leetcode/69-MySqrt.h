/************************************************************************************************************************
ʵ�� int sqrt(int x) ������

���㲢���� x ��ƽ���������� x �ǷǸ�������

���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��

ʾ�� 1:

����: 4
���: 2
ʾ�� 2:

����: 8
���: 2
˵��: 8 ��ƽ������ 2.82842...,
���ڷ���������������С�����ֽ�����ȥ��
************************************************************************************************************************/
#include<math.h>

class MySqrt {
public:
	//Ƥһ��
	int mySqrt1(int x) {
		return int(sqrt(x));
	}

	//���ַ��������������������ȫƽ����һ��λ��0~(n+1)/2֮�䣬���Լ���һ������
	//ִ�мӷ��ͳ˷�����һ��Ҫע��intԽ��
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
	//ţ�ٵ�����:f(x) = f(x0) + f'(x0)(x - x0) = 0
	//x = x0 - f(x0)/f'(x0)
	//y = x^2 - n
	//x = x0 - (x0*x0 - n)/2x0
	//	= x0/2 + n/2x0
	//  = (x0 + n/x0)/2 ,��һ�γ˷�
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