/************************************************************************************************************************
	You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

	You may assume the two numbers do not contain any leading zero, except the number 0 itself.

	Example:

	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8
	Explanation: 342 + 465 = 807.
************************************************************************************************************************/
#include<vector>

//Definition for singly - linked list;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//根据序列创建链表
ListNode *createList(vector<int>& nums) {
	ListNode* result = NULL;
	ListNode** temp = &result;
	for (int i = 0; i < nums.size(); ++i) {
		ListNode* node = new ListNode(nums[i]);
		*temp = node;
		temp = &node->next;
	}
	return result;
}

//比较两个链表是否相同
bool compareList(ListNode* l1, ListNode* l2) {
	
	if (l1 && l2)
		return true;

	while (l1 != NULL || l2 != NULL) {
		if (l1->val == l2->val) {
			l1 = l1->next;
			l2 = l2->next;
		}
		else {
			return false;
		}
	}
	return true;
}

class AddTwoNumbers {
public:
	//时间复杂度为O(max(m,n))
	//利用双指针可以实现链表的不断延续
	//最直接的方法是分别解码两个链表,求和之后再编码链表，复杂度为O(m+n+max(m,n))
	//&运算优先级低于->
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int sum = 0;
		ListNode* l3 = NULL;
		ListNode** temp = &l3;

		while (l1 != NULL || l2 != NULL || sum > 0) {
			if (l1 != NULL) {
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL) {
				sum += l2->val;
				l2 = l2->next;
			}
			ListNode* node = new ListNode(sum % 10);
			*temp = node;
			temp = &node->next;
			sum /= 10;
		}

		return l3;
	}
};