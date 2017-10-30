/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	//双指针 后面的比前面的落后n位 遍历一次即可
	//要注意只有0 1 2个元素这几个特殊情况 删除第一个元素的情况
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return NULL;
        ListNode* front = head;
        ListNode* behind = head;
        for(int i = 0; i < n; i++)
            behind = behind->next;
        while(behind != NULL && behind->next != NULL){
            front = front->next;
            behind = behind->next;
        }
        if(front == head && behind == NULL) return head->next;
        else front->next = front->next->next;
        return head;
    }
};