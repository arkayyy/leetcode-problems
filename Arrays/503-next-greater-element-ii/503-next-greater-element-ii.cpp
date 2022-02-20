class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size(),-1);
        for(int i = (nums.size()*2)-1; i>=0; i--) //since the array is rotated, we are considering two arrays side by side for ease of use
        {
            if(!s.empty())
            {
                while(!s.empty() && s.top()<=nums[i%nums.size()]) //popping until we get the next greater element of current element
                    s.pop();
                if(!s.empty()) ans[i%nums.size()] = s.top(); //setting the next greater element
            }
            s.push(nums[i%nums.size()]);
        }
        return ans;
    }
};