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
    bool hasCycle(ListNode *head) {
        
        if(!head ||!head->next) return false;
        
        ListNode* slo = head;
        ListNode* fast = head;
        slo = slo->next;
        fast = fast->next->next;
        
        while(fast && fast->next)
        {
            if(slo==fast)
                return true;
            slo = slo->next;
            fast = fast->next->next;
        }
        
        return false;
    }
};