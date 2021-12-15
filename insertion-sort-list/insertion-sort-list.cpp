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
        
        //creating a dummy node to connect before the head node, as it makes it easier to insert any node even if it wants to replace the head.
        ListNode* preHead = new ListNode(0);
        
        ListNode* prev = preHead;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr)
        {
            next = curr->next;
            //finding where to insert the current node value, from head to before current node
            while(prev->next && prev->next->val < curr->val)
            {
                prev = prev->next;
            }
            //inserting current node value between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;
            prev = preHead;
            //shifting curr to the next value, that needs to be inserted in the current sorted order 
            curr = next;
        }
        
        return preHead->next;
        
        
    }
};