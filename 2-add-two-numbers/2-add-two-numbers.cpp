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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int nodes1 = 0, nodes2 = 0;
        ListNode* curr1 = l1, *curr2 = l2;
        ListNode* head3 = new ListNode(-1);
        ListNode* curr3 = head3;
        int carry = 0;
        while(curr1 && curr2)
        {
            int s = curr1->val + curr2->val + carry;
            if(s>=10) {carry = 1; curr3->next = new ListNode(s-10);}
            else {carry = 0; curr3->next = new ListNode(s); }
            curr3 = curr3->next, curr1 = curr1->next, curr2 = curr2->next;
        }
        while(curr1) {
            int s = curr1->val+ carry;
            if(s>=10) {carry = 1; curr3->next = new ListNode(s-10);}
            else {carry = 0;curr3->next = new ListNode(s); }
            curr3 = curr3->next, curr1 = curr1->next;
        }
        while(curr2)
        {
            int s = curr2->val + carry;
            if(s>=10) {carry = 1; curr3->next = new ListNode(s-10);}
            else {carry = 0; curr3->next = new ListNode(s); }
            curr3 = curr3->next,curr2 = curr2->next;
        }
        if(carry)curr3->next = new ListNode(1);
        
        return head3->next;
    }
};