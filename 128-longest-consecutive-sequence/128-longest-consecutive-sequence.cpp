class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0 || nums.size()==1) return nums.size();
        set<int> s;
        for(auto n: nums)
            s.insert(n);
        
        int longest = 0;
        int prev = INT_MIN;
        int currSeq = 1;
        
        for(auto n: s)
        {
            if(prev==INT_MIN) 
                {prev = n; continue;}
            else if(n==prev+1) 
                currSeq++;
            else if(n!=prev+1) 
                {longest = max(longest, currSeq); currSeq = 1;}
            prev = n;
        }
        longest = max(longest, currSeq);
        return longest;
    }
};