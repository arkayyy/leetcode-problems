class Solution {
public:
    //INTUITION: simple backtracking, once adding an element to the current permutation and decrease its frequency in the map so next time it won't be added in the same permutation if its frequency <=0.
    //NOTE: If we take a visited array instead of map this won't work since different indexes can contain same elements here, so ultimately there maybe two same permutations present in the final answer.
    void permutate( vector<int> & curr, vector<vector<int>>& ans, unordered_map<int,int>& freq, vector<int> &nums)
    {
        if(curr.size()>nums.size()) return;
        if(curr.size()==nums.size()) {
            ans.push_back(curr);
            return;
        }

        for(auto &f: freq)//IMP: here we take reference to address of each element in the map, since we have to decrease every element's frequency once we include it in the current combination
        {
            if(f.second<=0) continue; //if the current element frequency has been used up, we don't include it anymore
            
            f.second--;
            curr.push_back(f.first);
            permutate(curr,ans,freq,nums);
            //backtracking steps:-
            curr.pop_back();
            f.second++;
        }
        
     }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> curr;
        unordered_map<int,int> freq;
        for(auto n:nums)
            freq[n]++; 
        permutate(curr,ans,freq,nums);
        return ans;
    }
};