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