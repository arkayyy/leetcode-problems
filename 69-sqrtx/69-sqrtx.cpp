class Solution {
public:
    int mySqrt(int x) {
        long long i =1;
        for( i = 1; i*i<=(long long)x; i++)
            continue;
        
        return (int)i-1;
    }
};