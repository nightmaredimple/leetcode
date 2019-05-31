////#include <iostream>
////#include <string>
////#include <unordered_map>
////
////using namespace std;
////int main()
////{
////	string s = "pwwkew";
////	unordered_map<char, int> record;
////	unordered_map<char, int>::iterator pos;
////
////	int maxlen = 0;
////	for (int i = 0; i < s.length(); ++i) {
////		pos = record.find(s[i]);
////		if (pos == record.end()) {
////			record[s[i]] = i;
////		}
////		else {
////			if (record.size() > maxlen)
////				maxlen = record.size();
////
////			record.erase(record.begin(), ++pos);
////			
////			record[s[i]] = i;
////		}
////		//for (pos = record.begin(); pos != record.end(); pos++)
////			//cout << pos->first << ":" << pos->second << endl;
////		//cout << "-----------" << endl;
////
////	}
////	cout << maxlen << endl;
////	
////	return 0;
////}
//#include <iostream>
//#include <string>
//#include <unordered_map>
//
//using namespace std;
//
//
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//	vector<int> &arr1 = nums1;
//	vector<int> &arr2 = nums2;
//	if (nums1.size() > nums2.size()) {
//		vector<int> &arr1 = nums2;
//		vector<int> &arr2 = nums1;
//	}
//	cout << arr1.size() << endl;
//	cout << arr2.size() << endl;
//	return 0;
//
//}
//
//int main()
//{
//	vector<int> nums2 = { 3, 4 };
//	vector<int> nums1 = { 1, 2, 5, 6 };
//	double res = findMedianSortedArrays(nums1, nums2);
//	//cout << res << endl;
//	return 0;
//}