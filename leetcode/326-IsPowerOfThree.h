/************************************************************************************************************************
����һ��������дһ���������ж����Ƿ��� 3 ���ݴη���

ʾ�� 1:

����: 27
���: true
ʾ�� 2:

����: 0
���: false
ʾ�� 3:

����: 9
���: true
ʾ�� 4:

����: 45
���: false
���ף�
���ܲ�ʹ��ѭ�����ߵݹ�����ɱ�����
************************************************************************************************************************/
//3^m / 3^n = 3^(m-n)
class IsPowerOfThree {
public:
	//ѭ��1
	//���ڲ���3�ı�����ʵ��Ч�ʸ���
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

	//ѭ��2
	//����n=3m�����Ч�ʸ���
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

	//�ݹ�
	//�ռ��ڴ��ʡ
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

	//ˣ��
	//����n�ϴ������Ч�ʲŸ�
	bool isPowerOfThree4(int n) {
		return n > 0 && !(1162261467 % n);
	}

};