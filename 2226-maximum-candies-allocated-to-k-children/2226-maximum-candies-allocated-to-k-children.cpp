class Solution {
public:

    int maximumCandies(vector<int>& candies, long long k) {
        int lo = 1, hi = 1e7;
        int ans = 0;
        while (lo <= hi) {
            long long res = 0, mid = lo+((hi-lo)>>1);
            for (int& c:candies) {
                res += c / mid;
            }
            if (k > res)
                { hi = mid - 1; }
            else //if(res>=k) because we need to allocate candies to atleast those k children            
               {ans = mid; lo = mid + 1;}
        }
        return ans;
    }
};