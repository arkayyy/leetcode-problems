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
    ListNode* removeNthFromEnd(ListNode* head, int n) { if(!head->next) return NULL;
        ListNode *prev = NULL, *p1 = head, *p2 = head;
        for(int i = 1; i<=n; i++)
            p2 = p2->next;
        while(p2) {prev = p1; p1 = p1->next; p2 = p2->next;}
        if(!prev) return head->next;
        prev->next = prev->next->next; 
        return head;
    }
};