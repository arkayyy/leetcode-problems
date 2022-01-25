class Solution {
public:
       int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long a = 0, ma = 0, mi = 0;
        for (int d: diff) {
            a += d;
            ma = max(ma, a);
            mi = min(mi, a);
        }
        if(mi<lower && ma>upper)
            return 0;
        return max(0L,(upper - lower) - (ma - mi) + 1);
    }
};