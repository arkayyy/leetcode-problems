class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;
        for(auto n: nums)
        {
            if(n<=max3 || n==max2 || n==max1) continue;
            max3 = n;
            if(max3>max2) swap(max3,max2);
            if(max2>max1) swap(max1,max2);
        }
        return max3==LLONG_MIN?(int)max1:(int)max3;
    }
};