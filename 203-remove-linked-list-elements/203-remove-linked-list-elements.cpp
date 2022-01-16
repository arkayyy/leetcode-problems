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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head;
        ListNode* temp = NULL;
        while(curr && curr->next)
        {
            temp = curr;
            while(curr->next && curr->next->val==val)
                curr = curr->next;
            temp->next = curr->next;
            curr = curr->next;
        }
        if(head && head->val==val) return head->next;
        return head;
    }
};