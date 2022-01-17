class Solution {
public:
    //INTUITION: simple backtracking, once adding an element to the current permutation and marking it visited so next time it won't be added in the same permutation.
    
    //NOTE:  If we have repeating elements in array, this won't work since different indexes can contain same elements here, so ultimately there maybe two same permutations present in the final answer. 
    //In that case we use simple backtracking with a map...
    //...once adding an element to the current permutation and decrease its frequency in the map so next time it won't be added in the same permutation if its frequency <=0.

    void permutate( vector<int> & curr, vector<vector<int>>& ans,  vector<bool>&visited, vector<int> &nums)
    {
        if(curr.size()>nums.size()) return;
        if(curr.size()==nums.size()) {
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i<nums.size(); i++) //we go through all elements of the array and we include any element that has not already been visited/added to the combination before.
        {
            if(!visited[i])
            {
                visited[i] = true;
                curr.push_back(nums[i]);
                permutate(curr,ans,visited,nums);
                //for backtracking:-
                visited[i] = false;
                curr.pop_back();
            }
        }
     }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(),false);
        vector<int> curr;
        permutate(curr,ans,visited,nums);
        return ans;
    }
};