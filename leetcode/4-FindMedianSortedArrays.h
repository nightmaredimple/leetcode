/************************************************************************************************************************
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
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
	//逐一比较两个数组的元素，比较暴力
	//时间复杂度O((m+n)/2)到O(min(m,n))之间，不符合题目要求，但速度还可以
	//代码设计自我感觉很垃圾

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
	其实通过O(log(m+n))就知道要用分治策略了,这里不能使用归并法先排序的思路，不然复杂度就是O((m+n)log(m+n))
	利用二分法进行求解会很简单:
	max(left_i,left_j) <= min(right_i, right_j)
	要注意j=(total1+total2+1)/2-(imin+imax)/2>=(2total1+1)/2-2total1/2=0，j>=i=0,=成立条件是total1=total2=0，否则j>=1
	划分为:0...i-1,i...m-1,imin<=i<=imax
		   0...j-1,j...n-1,j>0
	情况：
	(1)nums1[i-1]<=nums2[j],1<=i<=total1,  nums2[j-1]<nums1[i],0<=i<total1:
	   median = max(nums1[i-1],nums2[j-1]) or (max(nums1[i-1],nums2[j-1])+min(nums1[i]+nums2[j]))/2.0
	   要注意i=total1且m+n为偶数时，要单独考虑i=total1和j=total2的情形
	(2)nums1[i-1] > nums2[j], i>=1:
	   割点位于左半部分，即imax = i - 1
	(3)nums1[i] < nums2[j-1], i<total1:
	   割点位于右半部分，即imin = i + 1
	(4)i=0, total1=0:
		median = nums2的中位数,左侧仅存在nums2[0]~nums2[j-1]，右侧仅存在nums2[j]~nums2[n-1]
	(5)i=0, total1>0,nums1[i]>=nums2[j-1]:
		左侧仅存在nums2[0]~nums2[j-1]

	*****************************************************************************************************/
	//nums1和nums2不同时为空
	double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
		int total1 = nums1.size();
		int total2 = nums2.size();
		if (total1 > total2)
			return findMedianSortedArrays2(nums2, nums1);
		int half = (total1 + total2 + 1) / 2; //如果是(total1 +total2)/2的话，当total1=0，total2=1时,j=0，需要考虑j-1的问题
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