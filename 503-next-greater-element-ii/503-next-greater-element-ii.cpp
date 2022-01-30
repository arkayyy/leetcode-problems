class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size(),-1);
        for(int i = (nums.size()*2)-1; i>=0; i--)
        {
            if(!s.empty())
            {
                while(!s.empty() && s.top()<=nums[i%nums.size()])
                    s.pop();
                if(!s.empty()) ans[i%nums.size()] = s.top();
            }
            s.push(nums[i%nums.size()]);
        }
        return ans;
    }
};