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
    int getDecimalValue(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        
        while(curr){
            len++;
            curr = curr->next;
        }
        
        int ans = 0;
        
        curr = head;
        for(int i = len-1; i>=0 ;i--)
        {
            if(curr->val == 1)
                ans = ((1<<(i))|ans);
            curr = curr->next;
        }
        
        return ans;
    }
};