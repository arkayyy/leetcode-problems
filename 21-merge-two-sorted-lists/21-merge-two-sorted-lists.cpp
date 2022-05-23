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
    //INTUITION: Whichever node has smaller value, we put that first
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1, *curr2 = list2;
        ListNode* head3 = new ListNode(-1);
        ListNode* curr3 = head3;
        while(curr1 && curr2) { if(curr1->val<=curr2->val) curr3->next = curr1, curr1 = curr1->next;
            else curr3->next = curr2, curr2 = curr2->next;
            curr3 = curr3->next;
        }
        if(curr1) curr3->next = curr1;
        if(curr2) curr3->next = curr2;
        
        return head3->next;
    }
};