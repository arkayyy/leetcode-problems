class Solution {
public:
    //INTUITION & ALGO: We store all elements in a hash set and then check for sequences starting from every element...
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int longest = 0;
        for(auto n: s)
        {
            if(s.find(n-1)!=s.end()) continue; //e.g. if current element is already a part of a longer sequence 
            int j = 1; 
            while(s.find(n+j)!=s.end()) j++;
            longest = max(j,longest);
        }
        return longest;
    }
};