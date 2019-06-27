/************************************************************************************************************************
ͳ������С�ڷǸ����� n ��������������

ʾ��:

����: 10
���: 4
����: С�� 10 ������һ���� 4 ��, ������ 2, 3, 5, 7 ��
************************************************************************************************************************/
#include<math.h>
#include<iostream>
class CountPrimes {
public:
	//���
	//����ż���Լ�һ������
	int countPrimes1(int n) {
		if (n < 3)
			return 0;
		int res = 1;

		for (int i = 3; i < n; i += 2) {
			if (i % 2 == 0)
				continue;
			bool flag = true;
			int j = 3;
			while(j <= sqrt(i)) {
				if (i % j == 0) {
					flag = false;
					break;
				}
				j += 2;
			}
			if (flag)
				res++;

		}
		return res;
	}

	//һ����ȥ������ĳ���ӵ�����ֱ��sqrt(n)
	//��������ɸ��
	//�����ܱ����ظ�����
	int countPrimes2(int n) {
		if (n < 3)
			return 0;

		bool *arr = (bool*)malloc(n*sizeof(bool));
		memset(arr, true, n*sizeof(bool));

		for (int i = 3; i <= sqrt(n); i += 2) 
			if (arr[i]) 
				for (int j = i*i; j < n; j += i)//����j=i~i*(i-1)������j=i-1~��i-1��*i�д���
					arr[j] = false;
			
		int res = 1;
		arr[0] = false; arr[1] = false;
		for (int i = 3; i < n; i += 2)
			if (arr[i])
				res++;
		return res;

	}
};