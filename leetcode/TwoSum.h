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
	//时间复杂度:O(n^2),
	//空间复杂度:O(1)
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
	//时间复杂度: O(n)
	//空间复杂度: O(n)
	//level2
	vector<int> twoSum2(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int, int> m;
		unordered_map<int, int>::iterator pos;
		for (int i = 0; i < nums.size(); ++i) {
			pos = m.find(nums[i]);
			if (pos == m.end()) {
				pair<int, int> p(target - nums[i], i);
				m.insert(p);
			}
			else {
				result.push_back(pos->second);
				result.push_back(i);
				break;
			}
		}
		return result;
	}

	//时间复杂度: O(n)
	//空间复杂度: O(n)
	//level2
	//利用target-nums[i]: i 的pair对进行索引,即所需值：当前位置
	vector<int> twoSum3(vector<int> &numbers, int target) {
		unordered_map<int, int> m;
		vector<int> result;
		for (int i = 0; i < numbers.size(); i++) {

			if (m.find(numbers[i]) == m.end()) {

				m[target - numbers[i]] = i;
			}
			else {

				result.push_back(m[numbers[i]]);
				result.push_back(i);
				break;
			}
		}
		return result;
	}


};

