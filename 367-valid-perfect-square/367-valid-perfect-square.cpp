class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        int lo = 1, hi = num-1, mid;
        while(lo<=hi)
        {
            mid = lo+((hi-lo)>>1);
            if(pow(mid,2)==num) return true;
            else if(pow(mid,2)<num) lo=mid+1;
            else hi = mid-1;
        }
        return false;
    }
};