/************************************************************************************************************************
ʵ�� pow(x, n) �������� x �� n ���ݺ�����

ʾ�� 1:

����: 2.00000, 10
���: 1024.00000
ʾ�� 2:

����: 2.10000, 3
���: 9.26100
ʾ�� 3:

����: 2.00000, -2
���: 0.25000
����: 2-2 = 1/22 = 1/4 = 0.25
˵��:

-100.0 < x < 100.0
n �� 32 λ�з�������������ֵ��Χ�� [?2^31, 2^31 ? 1] ��
************************************************************************************************************************/
#include<math.h>
class MyPow {
public:
	//Ƥһ��
	double myPow1(double x, int n) {
		return pow(x, double(n));
	}

	//�����ⷨ��O(n)
	//n�ر���ʱ��϶��ᳬʱ
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

	//�ݹ飬���Ǹ��Ӷ�û��O(n)
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

	//�ݹ飬���Ӷ�O(logn),�����ܱ�֤�ݹ鲿�ֺ������
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