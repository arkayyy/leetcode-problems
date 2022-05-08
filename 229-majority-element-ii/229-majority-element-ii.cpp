class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Slightly different from the Majority Element I problem on Leetcode. There existed only one majority element which was more than 50% of the array.
        //Here we have two candidates at same time for both appearing more than 1/3rd of the array.
        //We can't have more than 2 candidates for the same, as that will exceed the length of the array.
        
        //ALGO: We take two candidates and two respective counts for them
        
        int n1 = -1, n2 = -1, c1 = 0, c2 = 0;
        for(auto n: nums)
        {
            if(n1==n) c1++;
            else if(n2==n) c2++;
            else if(c1==0) {n1 = n; c1++;}
            else if(c2==0) {n2 = n; c2++;}
            else c1--,c2--;
        }
        //now n1 and n2 store the potential candidates for appearing more than 1/3rd of the array each
        c1 = 0, c2 = 0;
        for(auto n: nums)
        {
            if(n==n1) c1++;
            else if(n==n2) c2++;
        }
        vector<int>ans;
        if(c1>(nums.size()/3)) ans.push_back(n1);
        if(c2>(nums.size()/3)) ans.push_back(n2);
        
        return ans;
    }
};