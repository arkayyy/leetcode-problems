class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i<nums.size(); i++)
        {
            sum+=((nums[i]==1)?1:-1);
            if(sum==0) ans = i+1; //if sum is 0 means the first element of a subarray is being taken
            else if(mp.find(sum)==mp.end()) mp[sum] = i; //this sum has not been encountered before so we associate it with current index
            else ans = max(ans, i-mp[sum]); //if this sum has been already encountered before means that all the elements between current index and that index sum is 0(i.e. same no. of 0(-1)'s and 1's).
        }
        return ans;
    }
};