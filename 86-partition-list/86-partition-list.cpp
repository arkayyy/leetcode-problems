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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        
        ListNode* prev = new ListNode(-1);
        
        ListNode* curr = head;
        ListNode* tail = new ListNode(-1);
        
        //checking starting nodes if they are >= x, then we continue till the first node less than x
        if(curr->val>=x)
        {
            tail = curr; //updating the starting point of the tail, that is going to be built
            ListNode* prev1 = NULL;
            while(curr && curr->val>=x)
            {
                prev1=curr;
                curr = curr->next;
            }
            prev1->next = NULL;
        }
        
        ListNode* newHead = curr; //newhead is at the first node encountered that has value < x
        
        if(!newHead) return head; //if newhead is null, means all the elements from starting are greater than x, so we directly return head
        
        ListNode* tailc = tail;
        
        while(tailc->next) tailc = tailc->next; //we forward to the lastmost node
        
        while(curr)
        {
            ListNode* prev1 = NULL;
            if(curr->val>=x)
            {
                tailc->next = curr;
                while(curr && curr->val >= x)
                {
                    prev1 = curr;
                    curr = curr->next;
                }
                prev1->next = NULL;
                prev->next = curr; 
                tailc = prev1;
            }
            
            else
                {prev = curr; curr = curr->next;} //prev stores the last node encountered that had value less than x
        }
        
        prev->next = tail->val==-1?tail->next: tail;
        return newHead;
    }
    
};