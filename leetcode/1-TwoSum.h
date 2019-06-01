/************************************************************************************************************************
	Given an array of integers, return indices of the two numbers such that they add up to a specific target.

	You may assume that each input would have exactly one solution, and you may not use the same element twice.

	Example:

	Given nums = [2, 7, 11, 15], target = 9,

	Because nums[0] + nums[1] = 2 + 7 = 9,
	return[0, 1].
************************************************************************************************************************/
#include<vector>
#include<unordered_map>
using namespace std;

class TwoSum {
public:
	//ʱ�临�Ӷ�:O(n^2),
	//�ռ临�Ӷ�:O(1)
	//level1
	vector<int> twoSum1(vector<int>& nums, int target) {
		vector<int> result;
		for (int i = 0; i < nums.size() - 1; ++i)
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[i] + nums[j] == target) {
					result.push_back(i);
					result.push_back(j);
					break;
				}
			}
		return result;
	}
	//ʱ�临�Ӷ�: O(n)
	//�ռ临�Ӷ�: O(n)
	//level2
	//insert��ϣ������һ��ֻ��ҪO(1)
	vector<int> twoSum2(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int, int> m;//�����ϣ��
		unordered_map<int, int>::iterator pos;//������
		for (int i = 0; i < nums.size(); ++i) {
			pos = m.find(nums[i]);//ָ���ϣ����key=nums[i]��λ��ָ��
			if (pos == m.end()) {//end()ָ���ϣ�����һ��Ԫ�ص���һ��Ԫ��λ��
				//pair<int, int> p(target - nums[i], i);
				m.insert(make_pair(target - nums[i], i));
			}
			else {
				result.push_back(pos->second);
				result.push_back(i);
				break;
			}
		}
		return result;
	}

	//ʱ�临�Ӷ�: O(n)
	//�ռ临�Ӷ�: O(n)
	//level2
	//ֱ�Ӳ����ϣ��
	vector<int> twoSum3(vector<int> &nums, int target) {
		unordered_map<int, int> m;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {

			if (m.find(nums[i]) == m.end()) {

				m[target - nums[i]] = i;//key=target-nums[i],value=i
			}
			else {

				result.push_back(m[nums[i]]);
				result.push_back(i);
				break;
			}
		}
		return result;
	}

};



