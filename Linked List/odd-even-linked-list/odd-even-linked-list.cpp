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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
         
        
        // 1->2->3->4->5->NULL
        ListNode* even = head->next; //starting from 2
        ListNode* evenHead = head->next; //storing the address of 2
        ListNode* odd = head; //starting from 1
        
        while(odd->next && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        
        odd->next = evenHead; //connecting the last head of odd no/th node to from where the even nodes start
        
        return head;
            
    }
};