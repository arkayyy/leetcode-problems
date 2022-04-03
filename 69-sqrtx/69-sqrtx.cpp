class Solution {
public:
    int mySqrt(int x) {
        //Normal method:-
//         long long i =1;
//         for( i = 1; i*i<=(long long)x; i++)
//             continue;
        
//         return (int)i-1;
        
        //Newton's method:-
        // long long r = x;
        // while (r*r > x)
        //     r = (r + x/r) / 2;
        // return r;
        
        //Binary search:-
        long long ans = 0;
        long long lo = 1, hi = INT_MAX;
        while(lo<=hi)
        {
            long long mid = lo+((hi-lo)>>1);
            if(mid*mid==(long long)x) return mid;
            if(mid*mid < x)
            {ans = mid; lo = mid+1;}
            else
                hi = mid-1;
        }
        
        return ans;
    }
};