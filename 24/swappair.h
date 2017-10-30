/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	//比较容易
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode* l1 = head;
        head = head->next;
        ListNode* f = NULL;
        while(l1 != NULL && l1->next != NULL){
            ListNode* temp = l1->next;
            l1->next = l1->next->next;
            temp->next = l1;
            if(f != NULL) f->next = temp;
            f = temp->next;
            l1 = f->next;
        }
        return head;
    }
};