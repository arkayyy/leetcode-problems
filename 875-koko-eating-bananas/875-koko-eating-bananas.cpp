class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(lo<=hi)
        {
            int mid = lo+((hi-lo)>>1);
            long long res = 0;
            for(auto&p:piles) res+=(p/mid)+(p%mid!=0);
            //if(res==h) return mid;
            if(res>h) lo = mid+1;
            else {ans = mid; hi = mid-1;}
        }
        return ans;
    }
};