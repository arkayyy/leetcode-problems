class Solution {
public:
    //INTUITION: The min. no of decibinary needed would obviously be denoted by the largest digit in the given number, becuase we'll need to add up that many 1's to get that digit
    int minPartitions(string n) {
        int ans = 0;
        for(auto c:n) ans = max(ans,c-'0');
        return ans;
    }
};