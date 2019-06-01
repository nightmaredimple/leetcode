/************************************************************************************************************************
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
	Output : 3
	Explanation : The answer is "abc", with the length of 3.
	Example 2 :

	Input : "bbbbb"
	Output : 1
	Explanation : The answer is "b", with the length of 1.
	Example 3 :

	Input : "pwwkew"
	Output : 3
	Explanation : The answer is "wke", with the length of 3.
	Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
************************************************************************************************************************/
#include<string>
#include<unordered_map>
using namespace std;
class LongestSubstringWithoutRepeatingCharacters {
public:
	//利用哈希表查询是否有重复元素，并修改其value对应的位置
	//unordered_map并非完全无序，不能信任
	int lengthOfLongestSubstring1(string s) {
		unordered_map<char, int> record;
		unordered_map<char, int>::iterator pos;
		int clen = -1;
		int maxlen = 0;
		for (int i = 0; i < s.length(); ++i) {
			pos = record.find(s[i]);
			if (pos != record.end() && record[s[i]] > clen) 
				clen = record[s[i]];

			if (i - clen > maxlen)
				maxlen = i - clen;

			record[s[i]] = i;
		}
		return maxlen;
	}

	//直接利用字符acsii码上限2^9-1代替哈希表
	int lengthOfLongestSubstring2(string s) {
		int m[256];
		memset(m, -1, sizeof(m));

		int clen = -1;
		int maxlen = 0;
		for (int i = 0; i<s.size(); i++) {
			if (m[s[i]] != -1 && clen < m[s[i]]) {
				clen = m[s[i]];
			}
			if (i - clen > maxlen) {
				maxlen = i - clen;
			}
			m[s[i]] = i;
		}
		return maxlen;
	}

};