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
//int main()
//{
//	std::unordered_map<std::string, std::string> mymap;
//
//	// populating container:
//	mymap["U.S."] = "Washington";
//	mymap["U.K."] = "London";
//	mymap["France"] = "Paris";
//	mymap["Russia"] = "Moscow";
//	mymap["China"] = "Beijing";
//	mymap["Germany"] = "Berlin";
//	mymap["Japan"] = "Tokyo";
//
//	// erase examples:
//	//mymap.erase(mymap.begin());      // erasing by iterator
//	//mymap.erase("France");             // erasing by key
//	//mymap.erase(mymap.find("China"), mymap.end()); // erasing by range
//
//												   // show content:
//	for (auto& x : mymap)
//		std::cout << x.first << ": " << x.second << std::endl;
//
//	return 0;
//}