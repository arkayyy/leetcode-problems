class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0, sum = 0;
        for(int g: gain)
            maxi = max(maxi, sum+=g);
        return max(maxi,sum);
    }
};