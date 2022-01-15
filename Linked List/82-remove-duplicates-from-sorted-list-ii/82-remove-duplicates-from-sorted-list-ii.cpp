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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head) return NULL;
        
        ListNode* curr = head;
        ListNode* prev = head;
        
        bool headRepeats = false; //if head node repeats we separate it at last (since we are initialising our prev node as head initially)
        if(head && head->next && head->val==head->next->val) headRepeats = true;
        
        while(curr && curr->next)
        {
            ListNode* temp = curr;
            if(curr->next && curr->val == curr->next->val)
            {
            while( curr->next && curr->val == curr->next->val) //moving until same continious elements are present
                curr = curr->next;
                
                prev->next = curr->next;
            }
            else //when the current element is non-repeating
            {
                prev = curr; //main part: we are memorising the previous non-repeating node everytime and changing it onlyy when we find another non-repeating element next in the LL. 
                //We won't change prev when we fina a repeating element.
            }
            curr = curr->next;
        }
        
        return headRepeats?head->next:head;
    }
};