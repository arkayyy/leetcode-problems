/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* preHead = new ListNode(-1);
        ListNode* prev = preHead;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr)
        {
            next = curr->next;
            while(prev->next && prev->next->val<curr->val)
                prev = prev->next;
            curr->next = prev->next;///
            prev->next = curr;
            prev = preHead;
            curr = next;
        }
        return preHead->next;
    }
    
};