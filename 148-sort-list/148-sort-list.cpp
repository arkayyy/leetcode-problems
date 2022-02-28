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
    
    ListNode* sortList(ListNode* head) {
        
        if(!head)
            return NULL;
        if(!head->next)     
            return head;
        
       // ListNode* mid = findMidNode(head);
        ListNode* first = head;
        ListNode* second = findMidNode(head);
       // mid->next = NULL;
        // first = sortList(first);
        // second = sortList(second);
        return merge(sortList(first),sortList(second));
    
    }
    
    
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* head3 = NULL;
        if(head1==NULL)
            return head2;
        if(head2==NULL)
            return head1;
        
        if(head1->val <= head2->val)
        {head3 = head1; head1=head1->next;}
        else
        {head3 = head2; head2=head2->next;}
        ListNode* univhead = head3;
        while(head1 && head2)
        {
            if(head1->val<=head2->val)
            {head3->next = head1; head3=head3->next; head1 = head1->next; }
            else
                {head3->next = head2; head3=head3->next; head2 = head2->next; }
        
        }
        head3->next = NULL;
        if(head1)
            {head3->next = head1; }
        
        if(head2)
            {head3->next = head2; }
        
        
        //RECURSIVE METHOD (TLE)
        
        // if(head1->val <= head2->val)
        //     {head3 = new ListNode(head1->val); head3->next = merge(head1->next,head2);}
        // else
        // {head3=new ListNode(head2->val); head3->next = merge(head1,head2->next);}
        
        
        
        return univhead;
    }
    
    ListNode* findMidNode(ListNode* head)
    {
        ListNode* slo = NULL;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slo=(!slo)?head:slo->next;
            fast=fast->next->next;
        }
        ListNode* t = slo->next;
        slo->next = NULL;
        return t;
    }
};