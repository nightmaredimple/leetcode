/************************************************************************************************************************
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
************************************************************************************************************************/
#include<math.h>
#include<iostream>
class CountPrimes {
public:
	//穷举
	//过滤偶数以及一半因子
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

	//一步步去除包含某因子的数，直至sqrt(n)
	//厄拉多塞筛法
	//尽可能避免重复处理
	int countPrimes2(int n) {
		if (n < 3)
			return 0;

		bool *arr = (bool*)malloc(n*sizeof(bool));
		memset(arr, true, n*sizeof(bool));

		for (int i = 3; i <= sqrt(n); i += 2) 
			if (arr[i]) 
				for (int j = i*i; j < n; j += i)//对于j=i~i*(i-1)，会在j=i-1~（i-1）*i中处理
					arr[j] = false;
			
		int res = 1;
		arr[0] = false; arr[1] = false;
		for (int i = 3; i < n; i += 2)
			if (arr[i])
				res++;
		return res;

	}
};