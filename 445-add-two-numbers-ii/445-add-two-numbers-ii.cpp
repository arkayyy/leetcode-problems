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
    //INTUITION: Reverse the LL's and add them from the beginning along with carry...
    ListNode* revLL(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = revLL(l1);
        l2 = revLL(l2);
        ListNode* c1 = l1;
        ListNode* prevC1 = NULL;
        ListNode* c2 = l2;
        bool carry = false;
        while(c1&&c2)
        {
            if(carry)
            {
                c1->val = c1->val+c2->val+1;
                if(c1->val >= 10)
                    c1->val %= 10;
                else
                    carry = false;
            }
            else
            {
                c1->val = c1->val+c2->val;
                if(c1->val >= 10)
                   {carry = true; c1->val %= 10;}
            }
            prevC1 = c1;
            c1=c1->next; c2=c2->next;
        }
        if(!c1&&!c2)
        {
            if(carry)
                prevC1->next = new ListNode(1);
        }
        else if(c1)
        {
            while(c1 && carry)
            {
                c1->val+=1;
                if(c1->val>=10)
                    c1->val%=10;
                else
                   {carry = false; break;}
                prevC1=c1;
                c1 = c1->next;
            }
            if(carry)
                prevC1->next  = new ListNode(1);
        }
        else if(c2)
        {
            prevC1->next = c2;
            c1 = c2;
            while(c1 && carry)
            {
                c1->val+=1;
                if(c1->val>=10)
                    c1->val%=10;
                else
                   {carry = false; break;}
                prevC1=c1;
                c1 = c1->next;
            }
            if(carry)
                prevC1->next  = new ListNode(1);
        }
        l1 = revLL(l1);
        return l1;
    }
};