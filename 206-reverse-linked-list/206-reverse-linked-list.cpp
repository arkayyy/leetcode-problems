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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL, *next = NULL, *curr = head;
        while(curr)
        {
            next = curr->next; //storing which was already the next of current node
            curr->next = prev; //switching the next node of current node to the previous node(which we keep updating at every step)
            prev = curr; //obvio, current node is going to be next node's previous node
            curr = next; //moving forward curr in the original given LL order
        }
        return prev;
    }
};