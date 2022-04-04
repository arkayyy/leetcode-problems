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
    ListNode* swapNodes(ListNode* head, int k) {
        
        //ALGO: We move a pointer k times ahead from the head and store this(node1), we initialise another pointer at head.
        //Between two pointers a gap of k has been established.
        //Now we move both pointers ahead at same pace, so when the ahead pointer reaches the end, another pointer would reside at k distance before the end.
        //We swap node1 and this pointer.
    
        int kk = k;
        ListNode* node1 = NULL;
        ListNode* node2 = NULL;
        ListNode* curr = head;
        while(curr)
        {
            node2 = (!node2)?NULL: node2->next;
            if(--k == 0)
            {
                node1 = curr;
                node2 = head;
            }
            curr = curr->next;
        }
        swap(node1->val, node2->val);
        
        return head;
    }
};