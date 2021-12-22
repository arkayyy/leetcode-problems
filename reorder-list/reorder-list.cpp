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
    private:
        ListNode* reverse(ListNode* head)
        {
            ListNode* curr = head;
            ListNode* next = NULL;
            ListNode* prev = NULL;
            
            while(curr)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            return prev;
        }
    
        ListNode* findMid(ListNode* head)
        {
            ListNode* slo = head;
            ListNode* fast = head;
            ListNode* prev = NULL;
            
            while(fast && fast->next)
            {
                prev = slo;
                slo = slo->next;
                fast = fast->next->next;
            }
            
            if(!fast)
                return prev;
            else
                return slo;
        }
    public:
        void reorderList(ListNode* head) {
            
            if(!head || !head->next) return;
            
            ListNode* mid = findMid(head);
            
            ListNode* p1 = head;
            ListNode* p2 = mid->next;
            
            mid->next = NULL;
            
            p2 = reverse(p2);
            
            while(p1 && p2)
            {
                ListNode* next1 = p1->next;
                ListNode* next2 = p2->next;
                
                p1->next = p2;
                p2->next = next1;
                
                p1 = next1;
                p2 = next2;
            }
            
            
            
            
        }
};