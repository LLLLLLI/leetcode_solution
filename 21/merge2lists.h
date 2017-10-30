/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        ListNode* small;
        ListNode* large;
        ListNode* result;
        if(l1->val < l2->val){
            small = l1;
            large = l2;
            result = l1;
        }else{
            small = l2;
            large = l1;
            result = l2;
        }
        while(large != NULL && small->next != NULL){
            if(large->val >= small->val && large->val < small->next->val){
                ListNode* temp = large;
                large = large->next;
                temp->next = small->next;
                small->next = temp;
            }
            small = small->next;
        }
        if(small->next == NULL)
            small->next = large;
        return result;
    }
};