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
    //INTUITION: Using monotonic stack concept
    //ALGO: keep numbers in stack in decreasing order from bottom to top, so whenever an element breaks the monotonicity it is popped.
    //Everytime, the topmost element of the stack is the next greater number to the current node. If stack is empty, no next greater element.
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> temp;
        ListNode* curr = head;
        while(curr)
            temp.push_back(curr->val), curr = curr->next;
        stack<int> st;
        vector<int> ans(temp.size());
        for(int i = temp.size()-1; i>=0; i--)
        {
            if(st.empty())
                ans[i] = 0;
            else
            {
                while(!st.empty() && st.top()<=temp[i])
                    st.pop();
                ans[i] = st.empty()?0:st.top();
            }
            st.push(temp[i]);
        }
        
        return ans;
    }
};