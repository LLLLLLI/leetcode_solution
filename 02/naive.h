/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	//直接new的话会覆盖原来的信息 要对next new
	//beats 95.55%!
public:
    	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ptr1 = l1;
		ListNode* ptr2 = l2;
		ListNode* result = new ListNode(0);
		ListNode* cal = result;
		int c = 0;
		int sum = 0;
		while (ptr1 != NULL && ptr2 != NULL)
		{
			sum = ptr1->val + ptr2->val + c;
			c = sum / 10;
			cal->next = new ListNode(sum - c * 10);
			cal = cal->next;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		if (ptr1 == NULL)
			ptr1 = ptr2;
		if (ptr1 == NULL)
		{
			if (c != 0)
				cal->next = new ListNode(c);
			return result->next;
		}
		else
		{
			l1 = ptr1;
			while (c > 0 && ptr1 != NULL)
			{
				if (ptr1->val + c >= 10)
				{
					ptr1->val = (ptr1->val + c) % 10;
					c = 1;
				}
				else
				{
					ptr1->val += c;
					c = 0;
					break;
				}
				l2 = ptr1;
				ptr1 = ptr1->next;
			}
			if (c>0)
				l2->next = new ListNode(c);
		}
		cal->next = l1;
		return result->next;
	}
     
};