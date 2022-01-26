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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* preHead = new ListNode(0);
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = preHead;
        while(curr)
        {
            next = curr->next;
            while(prev->next && prev->next->val<curr->val)
                prev = prev->next; //will stop when prev->next >= val, so we know that the curr node is to be inserted in between prev and prev->next
        
            //inserting curr in between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;
            //reinitialising prev for the next element's traversal iteration
            prev = preHead;
            curr = next; //curr moved to the next that we had stored before, because we have to follow the orginal sequence of the unsorted array.
        }
        
        return preHead->next;
    }
};