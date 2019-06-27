/************************************************************************************************************************
����������СΪ m �� n ���������� nums1 �� nums2��

�����ҳ������������������λ��������Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(log(m + n))��

����Լ��� nums1 �� nums2 ����ͬʱΪ�ա�

ʾ�� 1:

nums1 = [1, 3]
nums2 = [2]

����λ���� 2.0
ʾ�� 2:

nums1 = [1, 2]
nums2 = [3, 4]

����λ���� (2 + 3)/2 = 2.5
************************************************************************************************************************/
#include<vector>
#include<algorithm>
using namespace std;

class FindMedianSortedArrays {
public:
	double getmedian(int index, int total, double median, int median_pos, vector<int>& nums, bool flag) {
		if (median > 0)
			return (median + nums[index]) / 2.0;
		else {
			if (flag)
				return nums[median_pos - total];
			else
				return (nums[median_pos - total] + nums[median_pos - total + 1]) / 2.0;
		}
	}
	//��һ�Ƚ����������Ԫ�أ��Ƚϱ���
	//ʱ�临�Ӷ�O((m+n)/2)��O(min(m,n))֮�䣬��������ĿҪ�󣬵��ٶȻ�����
	//����������Ҹо�������

	double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
		int total1 = nums1.size();
		int total2 = nums2.size();
		int total = total1 + total2;
		int median_pos;

		double median = 0;
		bool flag = true;
		if (total % 2 == 0) {
			median_pos = total / 2 - 1;
			flag = false;
		}
		else
			median_pos = (total - 1) / 2;

		int i = 0, j = 0, pos = 0;
		while (i < total1 && j < total2) {
			bool x1 = (flag && pos == median_pos);
			bool x2 = (!flag && pos == median_pos);
			bool x3 = (!flag && pos == median_pos + 1);
			if (nums1[i] < nums2[j]) {
				if (x1 || x2 || x3) {
					median += nums1[i];
				}
				i++;
			}
			else {
				if (x1 || x2 || x3) {
					median += nums2[j];
				}
				j++;
			}
			if (x1)
				return median;
			else if (x3)
				return median / 2.0;

			pos++;
		}
		if (i < total1)
			return getmedian(i, total2, median, median_pos, nums1, flag);
		else
			return getmedian(j, total1, median, median_pos, nums2, flag);

	}


	/*****************************************************************************************************
	��ʵͨ��O(log(m+n))��֪��Ҫ�÷��β�����,���ﲻ��ʹ�ù鲢���������˼·����Ȼ���ӶȾ���O((m+n)log(m+n))
	���ö��ַ���������ܼ�:
	max(left_i,left_j) <= min(right_i, right_j)
	Ҫע��j=(total1+total2+1)/2-(imin+imax)/2>=(2total1+1)/2-2total1/2=0��j>=i=0,=����������total1=total2=0������j>=1
	����Ϊ:0...i-1,i...m-1,imin<=i<=imax
		   0...j-1,j...n-1,j>0
	�����
	(1)nums1[i-1]<=nums2[j],1<=i<=total1,  nums2[j-1]<nums1[i],0<=i<total1:
	   median = max(nums1[i-1],nums2[j-1]) or (max(nums1[i-1],nums2[j-1])+min(nums1[i]+nums2[j]))/2.0
	   Ҫע��i=total1��m+nΪż��ʱ��Ҫ��������i=total1��j=total2������
	(2)nums1[i-1] > nums2[j], i>=1:
	   ���λ����벿�֣���imax = i - 1
	(3)nums1[i] < nums2[j-1], i<total1:
	   ���λ���Ұ벿�֣���imin = i + 1
	(4)i=0, total1=0:
		median = nums2����λ��,��������nums2[0]~nums2[j-1]���Ҳ������nums2[j]~nums2[n-1]
	(5)i=0, total1>0,nums1[i]>=nums2[j-1]:
		��������nums2[0]~nums2[j-1]

	*****************************************************************************************************/
	//nums1��nums2��ͬʱΪ��
	double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
		int total1 = nums1.size();
		int total2 = nums2.size();
		if (total1 > total2)
			return findMedianSortedArrays2(nums2, nums1);
		int half = (total1 + total2 + 1) / 2; //�����(total1 +total2)/2�Ļ�����total1=0��total2=1ʱ,j=0����Ҫ����j-1������
		int imin = 0, imax = total1;
		int i, j;
		while (imin <= imax) {
			i = (imin + imax) / 2;
			j = half - i;
			if (i < total1 && nums1[i] < nums2[j - 1])
				imin = i + 1;
			else if (i &&nums1[i - 1] > nums2[j])
				imax = i - 1;
			else {
				int lmax = !i ? nums2[j - 1] : (!j ? nums1[i - 1] : max(nums1[i - 1], nums2[j - 1]));
				if ((total1 + total2) % 2 != 0)
					return lmax;
				int rmin = i == total1 ? nums2[j] : (j == total2 ? nums1[i] : min(nums1[i], nums2[j]));
				return 0.5 * (lmax + rmin);
			}
		}
		return 0.0;
	}
};