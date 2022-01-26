class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long maxi = 0, mini = 0;
        long temp = 0;
        for(int diff: differences)
        {
            temp+=diff;
            maxi = max(maxi, temp);
            mini = min(mini, temp);
        }
        return max(0L, (upper-maxi) + (mini - lower) +1);
    }
};