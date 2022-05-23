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
    //2-pointer technique: move one pointer at half the speed of other, so whenever the ahead pointer will reach the end of the LL, 
    //the slower pointer will stay at the middle!
    ListNode* middleNode(ListNode* head) {
        ListNode* slo = head, *fast = head;
        while(fast && fast->next) slo = slo->next, fast = fast->next->next;
        return slo;
    }
};