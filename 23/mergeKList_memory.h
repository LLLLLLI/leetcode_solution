/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	//用的归并
	//最后一组大数据总是会爆内存，没找到原因，有时间再仔细研究一下内存的管理吧
	//或者直接用智能指针
public:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
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
    ListNode* mergeKLists(vector<ListNode*> lists, int begin, int end) {  
        if(end - begin == 0) {  
            return NULL;  
        }  
        if(end - begin == 1) {  
            return lists[begin];  
        }   
        int mid = (end - begin)/2 + begin;  
        ListNode* l1 = mergeKLists(lists, begin, mid) ;  
        ListNode* l2 = mergeKLists(lists, mid, end) ;  
  
        return merge2Lists(l1,l2) ;  
    }  
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if(lists.size() < 100)
            return mergeKLists(lists, 0, lists.size());
        else
        {
            int i = lists.size() - 2;
            ListNode* l1 = mergeKLists(lists, i, lists.size());
            ListNode* p;
            while(i > 2){
                ListNode* l2 = mergeKLists(lists, i-2, i);
                i = i - 2;
                l1 = merge2Lists(l1, l2);
            }
            ListNode* l3 = mergeKLists(lists, 0, i);
            return merge2Lists(l1, l3);
        }
    }
};