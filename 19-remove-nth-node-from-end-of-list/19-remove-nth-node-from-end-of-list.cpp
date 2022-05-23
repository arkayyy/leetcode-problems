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
    //INTUITION: We take two pointers, and move one forward for n times, and then move both pointers ahead at same speed.
    //So when the ahead pointer reaches the end of LL, the slower one would be at the nth node from end of LL 
    ListNode* removeNthFromEnd(ListNode* head, int n) { if(!head->next) return NULL;
        ListNode *prev = NULL, *p1 = head, *p2 = head;
        for(int i = 1; i<=n; i++)
            p2 = p2->next;
        while(p2) {prev = p1; p1 = p1->next; p2 = p2->next;}
        
        //EDGE CASE ALERT: if we need to delete the starting node of the LL
        if(!prev) return head->next; //prev would still be NULL after initialising only in the case if the while loop above never runs, which denotes that p2 was already NULL after moving forward n nodes,
        //which means its the last node from the ending of the LL(i.e. the starting node of the LL) that we want to delete!
        
        prev->next = prev->next->next; 
        return head;
    }
};