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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        
        int l1 = 0, l2 = 0;
        while(h1)
        {
            h1 = h1->next; 
            l1++;
        }
        while(h2)
        {
            h2 = h2->next;
            l2++;
        }
        
        int diff = abs(l2-l1);
        
        if(l2>l1) 
        {
            while(diff--)
                headB = headB->next;
        }
        else
        {
             while(diff--)
                headA = headA->next;
        }
        
        while(headA && headB)
        {
            if(headA==headB)
                return headA;
            headA = headA->next; headB = headB->next;
        }
        return NULL;
        
        
    }
};