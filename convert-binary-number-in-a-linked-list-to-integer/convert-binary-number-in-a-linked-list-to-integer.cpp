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
        int ans = 0;
        
        //2 pass solution:-
        
//         while(curr){
//             len++;
//             curr = curr->next;
//         }
        

        
//         curr = head;
//         for(int i = len-1; i>=0 ;i--)
//         {
//             if(curr->val == 1)
//                 ans = ((1<<(i))|ans);
//             curr = curr->next;
//         }
        
        //1 pass soln.:-
        
        while(curr)
        {
            ans = ans<<1; //shifting all bits of ans by 1 to the left
            ans = (ans|(curr->val));//if a set bit occurs, the 0th bit of ans will be set
            curr = curr->next;
        }
        
        return ans;
    }
};