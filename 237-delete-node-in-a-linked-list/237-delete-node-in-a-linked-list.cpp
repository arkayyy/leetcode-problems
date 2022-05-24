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
    //INTUITION: Copy the value of next node in the to-be-deleted, connect it to the next to next node, and then delete the next node (stored).
    void deleteNode(ListNode* node) {
        ListNode* t = node->next;
        node->val = node->next->val;
        node->next=  node->next->next;
        delete t;
    }
};