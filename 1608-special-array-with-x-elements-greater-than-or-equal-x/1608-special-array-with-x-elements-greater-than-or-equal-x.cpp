class Solution {
public:
    int specialArray(vector<int>& nums) {
        int lo = 0, hi = nums.size();
        while(lo<=hi)
        {
            int mid = lo+((hi-lo)>>1);
            int cnt = 0;
            for(auto&n:nums) cnt+=n>=mid;
            if(cnt==mid) return mid;
            if(cnt>mid) lo = mid+1;
            else hi = mid-1;
        }
        return -1;
    }
};