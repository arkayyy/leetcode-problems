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
    
    ListNode* reverseLL(ListNode* head)
    {
        if(!head)
            return NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* util(ListNode* p1, ListNode* p2)
    {
        if(!p1 && !p2)
            return NULL;
        if(!p1)
            return p2;
        if(!p2)
            return p1;
        
        ListNode* next = p1->next;
        p1->next = p2;
        p2->next = util(next, p2->next);
        
        return p1;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        
        //Brute force approach (Recursive reversal of LL followed by reconnection) (NOT RECOMMENDED):-
        //head->next = reverseLL(head->next); //notice in the question, for every node if we reverse the whole linked list
        //on the right of that node and keep connecting the heads recursively, we will get the right answer.(Dry run on any array and see yourself to get the intuition)
        //reorderList(head->next);
        
        
        //OPTIMAL APPROACH - reverse the later half of the LL, put one one pointer on each half's starting node.
        //Keep connecting each pointer, and recursively go to next of each pointer
        ListNode* slo = head;
        ListNode* fast = head;
        ListNode* t = NULL;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(fast && fast->next)
        {
            t = slo;
            slo = slo->next;
            fast = fast->next->next;
        }
        
        
        while(slo)
        {
            next = slo->next;
            slo->next = prev;
            prev = slo;
            slo = next;
        }
        
        t->next = NULL;
        
        util(head,prev);
    }
};