class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mini = INT_MAX, minel;
        for(auto n: nums)
        {
            if(abs(n)<mini)
                mini = abs(n), minel = n;
            else if(abs(n)==mini)
                minel = max(minel,n);
        }
        return minel;
    }
};